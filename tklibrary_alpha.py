# Author: DotykProboszcza

root = tk.Tk()
root.title("Aplikacja ze szarym paskiem")

root.configure(bg="gray")

title_label = tk.Label(root, text="Tutaj jest miejsce na treść aplikacji", bg="gray", fg="white")
title_label.pack(fill=tk.BOTH, expand=True)

root.mainloop()