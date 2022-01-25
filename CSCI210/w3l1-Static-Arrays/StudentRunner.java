class StudentRunner {
    public static void main(String[] args) {

        System.out.println("Code by Raj Pabari");

        Student[] students = new Student[3];

        students[0] = new Student("John Doe", 3);
        students[0].setGrade(0, 95);
        students[0].setGrade(1, 97);
        students[0].setGrade(2, 100);

        students[1] = new Student("Jane Smith", 1);
        students[1].setGrade(0, 85);

        students[2] = new Student("Billy Bob", 2);
        students[2].setGrade(0, 91);
        students[2].setGrade(1, 89);

        for (Student i : students) {
            System.out.println(i);
        }
    }
}