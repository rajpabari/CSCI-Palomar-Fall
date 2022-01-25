import java.lang.Math;

public class Employee {
    private String firstName;
    private String lastName;
    private char gender;
    private int tenure;
    private char rate;
    private double salary;

    public Employee(String fName, String lName, String gen, String ten, String rat, String sal) {
        firstName = fName;
        lastName = lName;
        gender = gen.charAt(0);
        tenure = Integer.parseInt(ten);
        rate = rat.charAt(0);
        salary = Double.parseDouble(sal);
    }

    public int getTenure() {
        return tenure;
    }

    public String toString() {
        return "Name: " + firstName + " " + lastName + " Gender: " + gender + " Tenure: " + tenure + " Rate: " + rate
                + " Salary: $" + (Math.round(salary * 100.0) / 100.0);

    }

}
