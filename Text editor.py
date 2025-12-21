import tkinter as tk
from ctypes import *
import platform
from tkinter import filedialog

system = platform.system()

if system == "Darwin":          # macOS
    lib_path = "./c_ds/libds.dylib"
elif system == "Linux":
    lib_path = "./c_ds/libds.so"
elif system == "Windows":
    lib_path = "./c_ds/libds.dll"
else:
    raise OSError("Unsupported Operating System")

lib = CDLL(lib_path)
lib.init()

root = tk.Tk()
root.title("Text Editor")

text = tk.Text(root, width=80, height=25)
text.pack()

# Save current state to undo stack
def save_state():
    content = text.get("1.0", tk.END).encode()
    lib.push_undo(content)

def undo():
    current = text.get("1.0", tk.END).encode()
    lib.push_redo(current)

    buffer = create_string_buffer(10000)
    if lib.undo_action(buffer):
        text.delete("1.0", tk.END)
        text.insert(tk.END, buffer.value.decode())

def redo():
    current = text.get("1.0", tk.END).encode()
    lib.push_undo(current)

    buffer = create_string_buffer(10000)
    if lib.redo_action(buffer):
        text.delete("1.0", tk.END)
        text.insert(tk.END, buffer.value.decode())

def save_file():
    filename = filedialog.asksaveasfilename(
        defaultextension=".txt",
        filetypes=[("Text Files", "*.txt")]
    )

    if filename:
        content = text.get("1.0", tk.END).encode()
        lib.save(filename.encode(), content)

# Buttons
btn_frame = tk.Frame(root)
btn_frame.pack()

tk.Button(btn_frame, text="Undo", command=undo).pack(side=tk.LEFT, padx=5)
tk.Button(btn_frame, text="Redo", command=redo).pack(side=tk.LEFT, padx=5)
tk.Button(btn_frame, text="Save", command=save_file).pack(side=tk.LEFT, padx=5)

text.bind("<Key>", lambda e: save_state())

root.mainloop()
