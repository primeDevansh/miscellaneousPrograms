import java.util.Scanner;

class EnrolmentException extends Exception {
    public EnrolmentException(String message) {
        super(message);
    }
}

class Student {
    private String name;
    private int id;

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }
}

class Course {
    private String courseCode;
    private int maxCapacity;
    private int enrolledCount;

    public Course(String courseCode, int maxCapacity) {
        this.courseCode = courseCode;
        this.maxCapacity = maxCapacity;
        this.enrolledCount = 0;
    }

    public String getCourseCode() {
        return courseCode;
    }

    public int getMaxCapacity() {
        return maxCapacity;
    }

    public int getEnrolledCount() {
        return enrolledCount;
    }

    public void enrollStudent() throws EnrolmentException {
        if (enrolledCount >= maxCapacity) {
            throw new EnrolmentException("Course is full");
        }
        enrolledCount++;
    }
}

public class UniversityManager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Course javaCourse = new Course("CS101", 30);

        boolean exit = false;
        while (!exit) {
            System.out.println("\nUniversity Management System");
            System.out.println("1. Enroll Student");
            System.out.println("2. View Course Information");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    try {
                        javaCourse.enrollStudent();
                        System.out.println("Student enrolled successfully in course " + javaCourse.getCourseCode());
                    } catch (EnrolmentException e) {
                        System.out.println("Failed to enroll student: " + e.getMessage());
                    }
                    break;
                case 2:
                    System.out.println("Course Code: " + javaCourse.getCourseCode());
                    System.out.println("Max Capacity: " + javaCourse.getMaxCapacity());
                    System.out.println("Enrolled Count: " + javaCourse.getEnrolledCount());
                    break;
                case 3:
                    exit = true;
                    System.out.println("Exiting University Management System. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        }
        scanner.close();
    }
}
