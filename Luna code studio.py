import tkinter as tk
from tkinter import filedialog, simpledialog
import subprocess

class CodeEditor:
    def __init__(self, root):
        self.root = root
        self.root.title("LunaCode Studio")

        self.text_widget = tk.Text(
            self.root, wrap='word', undo=True, width=80, height=20, font=('Courier New', 12)
        )
        self.text_widget.pack(expand=True, fill='both', padx=10, pady=10)

        self.console_frame = tk.Frame(self.root)
        self.console_frame.pack(expand=True, fill='both', padx=10, pady=10)

        self.console_label = tk.Label(self.console_frame, text="Console", font=('Courier New', 12))
        self.console_label.pack()

        self.console_text = tk.Text(self.console_frame, wrap='word', undo=True, width=80, height=5, font=('Courier New', 12))
        self.console_text.pack(expand=True, fill='both')

        menu_bar = tk.Menu(self.root, font=('Courier New', 12))
        self.root.config(menu=menu_bar)

        file_menu = tk.Menu(menu_bar, tearoff=0, font=('Courier New', 12))
        menu_bar.add_cascade(label="File", menu=file_menu)
        file_menu.add_command(label="New", command=self.new_file)
        file_menu.add_command(label="Open", command=self.open_file)
        file_menu.add_command(label="Save", command=self.save_file)
        file_menu.add_command(label="Save As", command=self.save_file_as)
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=self.exit_app)

        run_menu = tk.Menu(menu_bar, tearoff=0, font=('Courier New', 12))
        menu_bar.add_cascade(label="Run", menu=run_menu)
        run_menu.add_command(label="Run Code", command=self.run_code)

        view_menu = tk.Menu(menu_bar, tearoff=0, font=('Courier New', 12))
        menu_bar.add_cascade(label="View", menu=view_menu)
        view_menu.add_command(label="Display Options", command=self.display_options)

        self.dark_mode = False
        self.custom_bg_color = None

    def new_file(self):
        self.text_widget.delete(1.0, tk.END)
        self.clear_console()

    def open_file(self):
        file_path = filedialog.askopenfilename(
            defaultextension=".txt", filetypes=[("Text files", "*.txt"), ("All files", "*.*")]
        )
        if file_path:
            with open(file_path, 'r') as file:
                content = file.read()
                self.text_widget.delete(1.0, tk.END)
                self.text_widget.insert(tk.END, content)
        self.clear_console()

    def save_file(self):
        content = self.text_widget.get(1.0, tk.END)
        file_path = filedialog.asksaveasfilename(
            defaultextension=".txt", filetypes=[("Text files", "*.txt"), ("All files", "*.*")]
        )
        if file_path:
            with open(file_path, 'w') as file:
                file.write(content)
        self.clear_console()

    def save_file_as(self):
        content = self.text_widget.get(1.0, tk.END)
        file_path = filedialog.asksaveasfilename(
            defaultextension=".txt", filetypes=[("Text files", "*.txt"), ("All files", "*.*")]
        )
        if file_path:
            with open(file_path, 'w') as file:
                file.write(content)
        self.clear_console()

    def exit_app(self):
        self.root.destroy()
    def run_code(self):
        code = self.text_widget.get(1.0, tk.END)
        try:
            result = subprocess.check_output(["python", "-c", code], stderr=subprocess.STDOUT, text=True)
            self.update_console(result)
        except subprocess.CalledProcessError as e:
            self.update_console(e.output)

    def clear_console(self):
        self.console_text.delete(1.0, tk.END)

    def update_console(self, content):
        self.console_text.insert(tk.END, content)

    def display_options(self):
        display_options_window = tk.Toplevel(self.root)
        display_options_window.title("Display Options")

        dark_mode_var = tk.BooleanVar(value=self.dark_mode)
        custom_bg_color_var = tk.StringVar(value=self.custom_bg_color)

        dark_mode_checkbox = tk.Checkbutton(
            display_options_window, text="Dark Mode", variable=dark_mode_var, font=('Courier New', 12)
        )
        dark_mode_checkbox.pack()

        custom_bg_color_button = tk.Button(
            display_options_window, text="Choose Background Color", command=lambda: self.choose_bg_color(custom_bg_color_var),
            font=('Courier New', 12)
        )
        custom_bg_color_button.pack()

        apply_button = tk.Button(
            display_options_window, text="Apply", command=lambda: self.apply_display_options(dark_mode_var.get(), custom_bg_color_var.get(), display_options_window),
            font=('Courier New', 12)
        )
        apply_button.pack()

    def choose_bg_color(self, var):
        color = tk.colorchooser.askcolor(title="Choose Background Color")
        if color[1]:
            var.set(color[1])

    def apply_display_options(self, dark_mode, bg_color, window):
        self.dark_mode = dark_mode
        self.custom_bg_color = bg_color

        # Apply visual changes based on the options
        if self.dark_mode:
            self.root.configure(bg='black')
            self.text_widget.configure(bg='black', fg='white')
            self.console_frame.configure(bg='black')
            self.console_text.configure(bg='black', fg='white')
        elif self.custom_bg_color:
            self.root.configure(bg=bg_color)
            self.text_widget.configure(bg=bg_color, fg='black')
            self.console_frame.configure(bg=bg_color)
            self.console_text.configure(bg=bg_color, fg='black')
        else:
            # Reset to default
            self.root.configure(bg='')
            self.text_widget.configure(bg='', fg='black')
            self.console_frame.configure(bg='')
            self.console_text.configure(bg='', fg='black')

        window.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    app = CodeEditor(root)
    root.mainloop()

