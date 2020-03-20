# CRUD operations on sqlite database

import sqlite3

conn = sqlite3.connect("student.db")
cur = conn.cursor()

cur.execute(
    """ 
    CREATE TABLE IF NOT EXISTS  students (
        student_id INTEGER PRIMARY KEY AUTOINCREMENT,
        first_name TEXT NOT NULL,
        last_name TEXT NOT NULL,
        roll_no INTEGER NOT NULL UNIQUE,
        branch TEXT NOT NULL
    ) 
    """
)

while True:
    choice = int(input("Enter your choice [0 - show menu]: "))

    if choice == 0:
        print("1. Insert data of new student")
        print("2. Update data of existing student")
        print("3. Delete data of existing student")
        print("4. Show data of a student")
        print("5. Show data of all students")
        print("Any other number to exit")

    elif choice == 1:
        first_name = input("Enter the first name: ")
        last_name = input("Enter the last name: ")
        roll_no = int(input("Enter the roll number: "))
        branch = input("Enter the branch: ")
        cur.execute(
            f""" INSERT INTO students (first_name, last_name, roll_no, branch) VALUES ("{first_name}", "{last_name}", "{roll_no}", "{branch}") """
        )
        conn.commit()

    elif choice == 2:
        roll_no = int(input("Enter the roll number: "))
        print("1. Update first name")
        print("2. Update last name")
        print("3. Update first and last name")
        print("4. Update branch")
        update_choice = int(input("Enter your choice: "))

        if update_choice == 1 or update_choice == 3:
            first_name = input("Enter the first name: ")
            cur.execute(
                f""" UPDATE students SET first_name = "{first_name}" WHERE roll_no = "{roll_no}" """
            )
            conn.commit()
        if update_choice == 2 or update_choice == 3:
            last_name = input("Enter the last name: ")
            cur.execute(
                f""" UPDATE students SET last_name = "{last_name}" WHERE roll_no = "{roll_no}" """
            )
            conn.commit()
        if update_choice == 4:
            branch = input("Enter the branch: ")
            cur.execute(
                f""" UPDATE students SET branch = "{branch}" WHERE roll_no = "{roll_no}" """
            )
            conn.commit()

    elif choice == 3:
        roll_no = int(input("Enter the roll number: "))
        cur.execute(
            f""" DELETE FROM students WHERE roll_no = "{roll_no}" """
        )
        conn.commit()
        print("Deleted roll number:", roll_no)

    elif choice == 4:
        roll_no = int(input("Enter the roll number: "))
        cur.execute(
            f""" SELECT * FROM students WHERE roll_no = "{roll_no}" """
        )
        student = cur.fetchone()

        if student is not None:
            print("First name\t\tLast name\t\tRoll no\t\t\tBranch")
            print(
                f"{student[1]}\t\t\t{student[2]}\t\t\t{student[3]}\t\t\t{student[4]}"
            )
        else:
            print("Student not found")

    elif choice == 5:
        students = cur.execute(
            """ SELECT * FROM students ORDER BY roll_no """
        )
        students = cur.fetchall()

        if len(students) > 0:
            print("First name\t\tLast name\t\tRoll no\t\t\tBranch")
            for student in students:
                print(
                    f"{student[1]}\t\t\t{student[2]}\t\t\t{student[3]}\t\t\t{student[4]}"
                )
        else:
            print("Database empty")

    else:
        print("Exited")
        break

conn.close()
