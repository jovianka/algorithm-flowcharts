import tkinter as tk
from tkinter import ttk
from ttkthemes import ThemedTk

class StudentDashboard:
    def __init__(self, root: ThemedTk):
        self.root = root
        self.root.title("University Student Dashboard")
        self.root.geometry("600x600")

        # Set the font styles
        self.font_style = ("Segoe UI", 14)
        self.heading_font = ("Segoe UI", 24, "bold")

        # Mainframe
        self.mainframe = ttk.Frame(self.root)
        self.mainframe.grid(column=0, row=0, sticky="nwes")
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)

        # Create the main menu
        self.create_main_menu()

    def create_main_menu(self):
        # Clear the window
        for widget in self.mainframe.winfo_children():
            widget.destroy()

        # Add the title label with modern font and style
        title_label = ttk.Label(self.mainframe, text="Student Dashboard", font=self.heading_font)
        title_label.pack(pady=40)

        # Create the buttons with modern design using a blue monochrome palette
        self.create_button("My Courses", self.show_courses)
        self.create_button("My Grades", self.show_grades)
        self.create_button("Assignments", self.show_assignments)
        self.create_button("My Profile", self.show_profile)

    def create_button(self, text, command):
        # Create a modern-looking button with padding, rounded corners, and a hover effect
        button = ttk.Button(self.mainframe, text=text, command=command, style="TButton")
        button.pack(pady=10)

    def show_courses(self):
        # Clear the window
        for widget in self.mainframe.winfo_children():
            widget.destroy()

        # Display courses with modern layout
        label = ttk.Label(self.mainframe, text="Courses Enrolled", font=("Segoe UI", 20, "bold"))
        label.pack(pady=20)

        courses = ["Mathematics 101", "Physics 102", "Computer Science 201"]
        for course in courses:
            course_label = ttk.Label(self.mainframe, text=course)
            course_label.pack(pady=5)

        # Back Button
        self.create_back_button()

    def show_grades(self):
        # Clear the window
        for widget in self.mainframe.winfo_children():
            widget.destroy()

        # Display grades with modern layout
        label = ttk.Label(self.mainframe, text="My Grades", font=("Segoe UI", 20, "bold"))
        label.pack(pady=20)

        grades = {
            "Mathematics 101": "A",
            "Physics 102": "B+",
            "Computer Science 201": "A-"
        }
        for course, grade in grades.items():
            grade_label = ttk.Label(self.mainframe, text=f"{course}: {grade}")
            grade_label.pack(pady=5)

        # Back Button
        self.create_back_button()

    def show_assignments(self):
        # Clear the window
        for widget in self.mainframe.winfo_children():
            widget.destroy()

        # Display assignments with modern layout
        label = ttk.Label(self.mainframe, text="Upcoming Assignments", font=("Segoe UI", 20, "bold"))
        label.pack(pady=20)

        assignments = [
            {"name": "Math Homework 1", "due_date": "2024-12-01"},
            {"name": "Physics Lab Report", "due_date": "2024-12-05"},
            {"name": "CS Project", "due_date": "2024-12-10"}
        ]
        for assignment in assignments:
            assignment_label = ttk.Label(self.mainframe, text=f"{assignment['name']} - Due: {assignment['due_date']}")
            assignment_label.pack(pady=5)

        # Back Button
        self.create_back_button()

    def show_profile(self):
        # Clear the window
        for widget in self.mainframe.winfo_children():
            widget.destroy()

        # Display profile info with modern layout
        label = ttk.Label(self.mainframe, text="My Profile", font=("Segoe UI", 20, "bold"))
        label.pack(pady=20)

        profile_info = {
            "Name": "John Doe",
            "Student ID": "12345678",
            "Email": "john.doe@example.com",
            "Major": "Computer Science"
        }
        for key, value in profile_info.items():
            info_label = ttk.Label(self.mainframe, text=f"{key}: {value}")
            info_label.pack(pady=5)

        # Back Button
        self.create_back_button()

    def create_back_button(self):
        back_button = ttk.Button(self.mainframe, text="Back", command=self.create_main_menu, style="TButton")
        back_button.pack(pady=20)

if __name__ == "__main__":
    root = ThemedTk(theme="yaru")
    dashboard = StudentDashboard(root)
    root.mainloop()
