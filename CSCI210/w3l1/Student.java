public class Student {
    private int[] grades;
    private String name;

    public Student(String studentName, int numGrades) {
        name = studentName;
        grades = new int[numGrades];
    }

    public String toString() {
        String ans = name + ": ";
        for (int i : grades) {
            ans += i + " ";
        }
        return ans;
    }

    public void setGrade(int index, int grade) {
        grades[index] = grade;
    }
}
