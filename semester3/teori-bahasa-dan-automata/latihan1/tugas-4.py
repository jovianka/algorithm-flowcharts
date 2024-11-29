import tkinter as tk
from tkinter import ttk

class StudentDashboard:
    def __init__(self, root):
        self.root = root
        self.root.title("University Student Dashboard")
        self.root.geometry("600x600")
        self.root.configure(bg="#2E2E2E")  # Dark background

        # Set the font styles
        self.font_style = ("Segoe UI", 14)
        self.heading_font = ("Segoe UI", 24, "bold")
        
        # Create the main menu
        self.create_main_menu()

    def create_main_menu(self):
        # Clear the window
        for widget in self.root.winfo_children():
            widget.destroy()

        # Add the title label with modern font and style
        title_label = tk.Label(self.root, text="Student Dashboard", font=self.heading_font, bg="#2E2E2E", fg="#FFFFFF")
        title_label.pack(pady=40)

        # Create the buttons with modern design using a blue monochrome palette
        self.create_button("My Courses", self.show_courses)
        self.create_button("My Grades", self.show_grades)
        self.create_button("Assignments", self.show_assignments)
        self.create_button("My Profile", self.show_profile)

    def create_button(self, text, command):
        # Create a modern-looking button with padding, rounded corners, and a hover effect
        button = tk.Button(self.root, text=text, width=20, height=2, command=command,
                        font=self.font_style, bg="#2196F3", fg="white", relief="flat", bd=0, borderwidth=0,
                        highlightthickness=0)  # Ensure no border (bd=0, borderwidth=0, highlightthickness=0)
        button.pack(pady=10)
        button.bind("<Enter>", lambda e: button.config(bg="#1976D2"))  # Hover effect (slightly darker blue)
        button.bind("<Leave>", lambda e: button.config(bg="#2196F3"))  # Reset hover effect to original blue

    def show_courses(self):
        # Clear the window
        for widget in self.root.winfo_children():
            widget.destroy()

        # Display courses with modern layout
        label = tk.Label(self.root, text="Courses Enrolled", font=("Segoe UI", 20, "bold"), bg="#2E2E2E", fg="#FFFFFF")
        label.pack(pady=20)

        courses = ["Mathematics 101", "Physics 102", "Computer Science 201"]
        for course in courses:
            course_label = tk.Label(self.root, text=course, font=self.font_style, bg="#2E2E2E", fg="#CCCCCC")
            course_label.pack(pady=5)

        # Back Button
        self.create_back_button()

    def show_grades(self):
        # Clear the window
        for widget in self.root.winfo_children():
            widget.destroy()

        # Display grades with modern layout
        label = tk.Label(self.root, text="My Grades", font=("Segoe UI", 20, "bold"), bg="#2E2E2E", fg="#FFFFFF")
        label.pack(pady=20)

        grades = {
            "Mathematics 101": "A",
            "Physics 102": "B+",
            "Computer Science 201": "A-"
        }
        for course, grade in grades.items():
            grade_label = tk.Label(self.root, text=f"{course}: {grade}", font=self.font_style, bg="#2E2E2E", fg="#CCCCCC")
            grade_label.pack(pady=5)

        # Back Button
        self.create_back_button()

    def show_assignments(self):
        # Clear the window
        for widget in self.root.winfo_children():
            widget.destroy()

        # Display assignments with modern layout
        label = tk.Label(self.root, text="Upcoming Assignments", font=("Segoe UI", 20, "bold"), bg="#2E2E2E", fg="#FFFFFF")
        label.pack(pady=20)

        assignments = [
            {"name": "Math Homework 1", "due_date": "2024-12-01"},
            {"name": "Physics Lab Report", "due_date": "2024-12-05"},
            {"name": "CS Project", "due_date": "2024-12-10"}
        ]
        for assignment in assignments:
            assignment_label = tk.Label(self.root, text=f"{assignment['name']} - Due: {assignment['due_date']}", font=self.font_style, bg="#2E2E2E", fg="#CCCCCC")
            assignment_label.pack(pady=5)

        # Back Button
        self.create_back_button()

    def show_profile(self):
        # Clear the window
        for widget in self.root.winfo_children():
            widget.destroy()

        # Display profile info with modern layout
        label = tk.Label(self.root, text="My Profile", font=("Segoe UI", 20, "bold"), bg="#2E2E2E", fg="#FFFFFF")
        label.pack(pady=20)

        profile_info = {
            "Name": "John Doe",
            "Student ID": "12345678",
            "Email": "john.doe@example.com",
            "Major": "Computer Science"
        }
        for key, value in profile_info.items():
            info_label = tk.Label(self.root, text=f"{key}: {value}", font=self.font_style, bg="#2E2E2E", fg="#CCCCCC")
            info_label.pack(pady=5)

        # Back Button
        self.create_back_button()

    def create_back_button(self):
        # Back button with modern style using a blue variant
        back_button = tk.Button(self.root, text="Back", width=20, height=2, command=self.create_main_menu,
                                font=self.font_style, bg="#2196F3", fg="white", relief="flat", bd=0, borderwidth=0,
                                highlightthickness=0)  # Ensure no border (bd=0, borderwidth=0, highlightthickness=0)
        back_button.pack(pady=20)
        back_button.bind("<Enter>", lambda e: back_button.config(bg="#42A5F5"))  # Hover effect (darker blue)
        back_button.bind("<Leave>", lambda e: back_button.config(bg="#2196F3"))  # Reset hover effect

if __name__ == "__main__":
    root = tk.Tk()
    dashboard = StudentDashboard(root)
    root.mainloop()
