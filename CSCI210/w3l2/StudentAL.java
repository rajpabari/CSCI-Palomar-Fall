import java.util.ArrayList;

//had to name this object StudentAL (StudentArrayList) because VSCode can't have
//duplicate filenames on the class path

class StudentAL {
    private ArrayList<Integer> grades;
    private String name;

    public StudentAL(String studentName, int numGrades) {
        name = studentName;
        grades = new ArrayList<Integer>(numGrades);

        /*
         * set the default value to 0 to avoid any index adding errors for instance if
         * setGrade used the .add(int index,Integer element) and the first call was
         * .add(2,90) it would throw an error otherwise
         */
        for (int i = 0; i < numGrades; i++) {
            grades.add(0);
        }
    }

    public String toString() {
        String ans = name + ": ";
        for (Integer i : grades) {
            ans += i.intValue() + " ";
        }
        return ans;
    }

    public void setGrade(int index, int grade) {
        grades.set(index, grade);
    }
}
