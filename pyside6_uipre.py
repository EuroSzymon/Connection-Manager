# Author: DotykProboszcza
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel

class MyMainWindow(QMainWindow):
    def init(self):
        super().init()

        # Ustawienia okna głównego
        self.setWindowTitle("Aplikacja ze szarym paskiem")
        self.setGeometry(100, 100, 600, 400)

        # Ustawienie koloru tła na szary
        self.setStyleSheet("background-color: gray;")

        # Dodanie etykiety na pasek tytułowy
        titlelabel = QLabel("Tutaj jest miejsce na treść aplikacji", self)
        titlelabel.setStyleSheet("color: white;")  # Ustawienie koloru czcionki na biały
        titlelabel.setGeometry(0, 0, 600, 30)  # Geometria etykiety (cały pasek tytułowy)

if _name == "__main":
    app = QApplication(sys.argv)
    window = MyMainWindow()
    window.show()
    sys.exit(app.exec())
