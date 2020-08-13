import tkinter as tk
import tkinter.filedialog as fdialog
import os

window = tk.Tk()
font = ("Helvetica", 12)

file_load = None


def load_file():
    file_load = fdialog.askopenfilename(
        initialdir="/", title="Select file", filetypes=[("Rich Text Format files", "*.rtf")])

    if file_load is None or file_load == "":
        text_frame_label["text"] = "Error: Python was unable\nto load file. Try again."
        open_file_label['text'] = "ERROR"

    elif file_load is not None:
        text_frame_label["text"] = "Imported {file_name}\n Press OK to begin.".format(
            file_name=os.path.basename(file_load))
        if len(os.path.abspath(file_load)) >= 34:
            open_file_label['font'] = ("Helvetica", 10)
        else:
            open_file_label['font'] = ("Helvetica", 12)
        open_file_label['text'] = os.path.abspath(file_load)
        go_button.configure(state="normal", text="OK", bg="#001011", fg="#64E9EE")


window.title("ProPresenter Auto-formatter")

canvas = tk.Canvas(window, bg="#97C8EB", height=400, width=400)
canvas.pack()

get_file_frame = tk.Frame(window, bd=5, bg="#093A3E")
get_file_frame.place(relx=0.5, rely=0.05, relwidth=0.85, height=40, anchor="n")

open_file_label = tk.Label(get_file_frame, font=("Helvetica", 10), relief="flat", justify="left")
open_file_label.place(relwidth=0.75, relheight=1)

open_button = tk.Button(get_file_frame, text="Open", font=font,
                        relief="flat", fg="#001011", command=load_file)
open_button.place(relx=1, relwidth=0.23, relheight=1, anchor="ne")

text_frame = tk.Frame(window, bd=5, bg="#093A3E")
text_frame.place(relx=0.5, rely=0.20, relwidth=0.85, relheight=0.60, anchor="n")

text_frame_label = tk.Label(text_frame, bg="white", font=("Helvetica", 16))
text_frame_label.place(relwidth=1, relheight=1)

go_button = tk.Button(window, text="NOT READY", font=("Helvetica", 16),
                      bg="#97C8EB", relief="flat", fg="#64E9EE", state="disabled")
go_button.place(relx=0.5, rely=0.82, relwidth=0.85, relheight=0.08, anchor="n")

window.mainloop()
