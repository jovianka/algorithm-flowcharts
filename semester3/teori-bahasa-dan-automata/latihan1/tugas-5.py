import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout, QLabel, QPushButton, QHBoxLayout, QStackedWidget
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QFont, QColor, QPalette


class StudentDashboard(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("University Student Dashboard")
        self.setGeometry(100, 100, 800, 500)  # Window size and position
        
        # Set dark monochrome blue color palette
        self.set_dark_theme()

        # Central Widget
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        # Set up a stacked widget to switch between different views (Courses, Grades, etc.)
        self.stacked_widget = QStackedWidget()

        # Create Pages
        self.create_dashboard_page()
        self.create_courses_page()
        self.create_grades_page()

        self.stacked_widget.addWidget(self.dashboard_page)
        self.stacked_widget.addWidget(self.courses_page)
        self.stacked_widget.addWidget(self.grades_page)

        layout = QVBoxLayout(self.central_widget)
        layout.addWidget(self.stacked_widget)

        self.show_dashboard_page()

    def set_dark_theme(self):
        """Apply the dark monochrome blue theme"""
        palette = QPalette()
        palette.setColor(QPalette.ColorRole.Window, QColor(30, 30, 30))  # Dark background
        palette.setColor(QPalette.ColorRole.WindowText, QColor(255, 255, 255))  # White text
        palette.setColor(QPalette.ColorRole.Base, QColor(45, 45, 45))  # Dark base for widgets
        palette.setColor(QPalette.ColorRole.AlternateBase, QColor(50, 50, 50))  # Slightly lighter background for alternate widgets
        palette.setColor(QPalette.ColorRole.ToolTipBase, QColor(255, 255, 255))
        palette.setColor(QPalette.ColorRole.ToolTipText, QColor(0, 0, 0))

        palette.setColor(QPalette.ColorRole.Text, QColor(255, 255, 255))  # White text for text fields
        palette.setColor(QPalette.ColorRole.Button, QColor(50, 50, 50))  # Dark buttons
        palette.setColor(QPalette.ColorRole.ButtonText, QColor(255, 255, 255))  # White button text
        palette.setColor(QPalette.ColorRole.Highlight, QColor(30, 144, 255))  # Blue highlight color

        self.setPalette(palette)

    def create_dashboard_page(self):
        """Create the main dashboard page"""
        self.dashboard_page = QWidget()
        layout = QVBoxLayout(self.dashboard_page)

        # Header
        header_label = QLabel("Welcome to Your Dashboard!")
        header_label.setFont(QFont("Helvetica", 24, QFont.Weight.Bold))
        header_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        layout.addWidget(header_label)

        # Student Info Section
        student_info = QLabel("Name: John Doe\nID: 12345678\nCourse: Computer Science", self)
        student_info.setFont(QFont("Helvetica", 16))
        student_info.setAlignment(Qt.AlignmentFlag.AlignCenter)
        layout.addWidget(student_info)

        # Buttons for navigating
        button_layout = QHBoxLayout()

        btn_courses = QPushButton("View Courses")
        btn_courses.clicked.connect(self.show_courses_page)
        btn_courses.setStyleSheet("background-color: #1E90FF; color: white; font-size: 16px; padding: 10px; border-radius: 5px;")
        button_layout.addWidget(btn_courses)

        btn_grades = QPushButton("View Grades")
        btn_grades.clicked.connect(self.show_grades_page)
        btn_grades.setStyleSheet("background-color: #1E90FF; color: white; font-size: 16px; padding: 10px; border-radius: 5px;")
        button_layout.addWidget(btn_grades)

        btn_logout = QPushButton("Log Out")
        btn_logout.clicked.connect(self.logout)
        btn_logout.setStyleSheet("background-color: #ff4f4f; color: white; font-size: 16px; padding: 10px; border-radius: 5px;")
        button_layout.addWidget(btn_logout)

        layout.addLayout(button_layout)

    def create_courses_page(self):
        """Create the courses page"""
        self.courses_page = QWidget()
        layout = QVBoxLayout(self.courses_page)

        # Title
        title_label = QLabel("Your Courses")
        title_label.setFont(QFont("Helvetica", 24, QFont.Weight.Bold))
        title_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        layout.addWidget(title_label)

        # List of Courses (Placeholder Data)
        courses_list = QLabel("1. Data Structures\n2. Algorithms\n3. Operating Systems\n4. Machine Learning", self)
        courses_list.setFont(QFont("Helvetica", 16))
        courses_list.setAlignment(Qt.AlignmentFlag.AlignCenter)
        courses_list.setStyleSheet("line-height: 1.5pt;")  # Set line height to 1.5pt
        layout.addWidget(courses_list)

        # Back Button
        back_button = QPushButton("Back to Dashboard")
        back_button.clicked.connect(self.show_dashboard_page)
        back_button.setStyleSheet("background-color: #1E90FF; color: white; font-size: 16px; padding: 10px; border-radius: 5px;")
        layout.addWidget(back_button)

        layout.setAlignment(Qt.AlignmentFlag.AlignCenter)  # Center all content on the page
        layout.setSpacing(20)  # Space between widgets
        layout.setContentsMargins(20, 20, 20, 20)  # Margin around the content

    def create_grades_page(self):
        """Create the grades page"""
        self.grades_page = QWidget()
        layout = QVBoxLayout(self.grades_page)

        # Title
        title_label = QLabel("Your Grades")
        title_label.setFont(QFont("Helvetica", 24, QFont.Weight.Bold))
        title_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        layout.addWidget(title_label)

        # List of Grades (Placeholder Data)
        grades_list = QLabel("1. Data Structures: A\n2. Algorithms: B+\n3. Operating Systems: A\n4. Machine Learning: B", self)
        grades_list.setFont(QFont("Helvetica", 16))
        grades_list.setAlignment(Qt.AlignmentFlag.AlignCenter)
        grades_list.setStyleSheet("line-height: 1.5pt;")  # Set line height to 1.5pt
        layout.addWidget(grades_list)

        # Back Button
        back_button = QPushButton("Back to Dashboard")
        back_button.clicked.connect(self.show_dashboard_page)
        back_button.setStyleSheet("background-color: #1E90FF; color: white; font-size: 16px; padding: 10px; border-radius: 5px;")
        layout.addWidget(back_button)

        layout.setAlignment(Qt.AlignmentFlag.AlignCenter)  # Center all content on the page
        layout.setSpacing(20)  # Space between widgets
        layout.setContentsMargins(20, 20, 20, 20)  # Margin around the content

    def show_dashboard_page(self):
        """Show the dashboard page"""
        self.stacked_widget.setCurrentWidget(self.dashboard_page)

    def show_courses_page(self):
        """Show the courses page"""
        self.stacked_widget.setCurrentWidget(self.courses_page)

    def show_grades_page(self):
        """Show the grades page"""
        self.stacked_widget.setCurrentWidget(self.grades_page)

    def logout(self):
        """Logout action (Close the app)"""
        print("Logging out...")
        self.close()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = StudentDashboard()
    window.show()
    sys.exit(app.exec())
