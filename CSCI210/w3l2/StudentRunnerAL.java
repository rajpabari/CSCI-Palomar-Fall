import java.util.ArrayList;

class StudentRunnerAL {
    public static void main(String[] args) {

        System.out.println("Code by Raj Pabari");

        ArrayList<StudentAL> students = new ArrayList<StudentAL>(3);

        students.add(new StudentAL("John Doe", 3));
        students.get(0).setGrade(0, 95);
        students.get(0).setGrade(1, 97);
        students.get(0).setGrade(2, 100);

        students.add(new StudentAL("Jane Smith", 1));
        students.get(1).setGrade(0, 85);

        students.add(new StudentAL("Billy Bob", 2));
        students.get(2).setGrade(0, 91);
        students.get(2).setGrade(1, 89);

        for (StudentAL i : students) {
            System.out.println(i);
        }
    }
}