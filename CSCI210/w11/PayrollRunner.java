import java.io.IOException;

public class PayrollRunner {
    public static void main(String[] args) {
        System.out.println("Code by Raj Pabari\nPayroll Processing Program");
        try {
            PayrollFile file = new PayrollFile("./CSCI210/w11/payroll.txt");
            String currentLine = file.getNextLine();
            Payroll payroll = new Payroll();
            String[] currentLineParsed;
            do {
                currentLineParsed = currentLine.strip().split("\\s+");
                Employee emp = new Employee(currentLineParsed[0], currentLineParsed[1], currentLineParsed[2],
                        currentLineParsed[3], currentLineParsed[4], currentLineParsed[5]);
                payroll.addEmployee(emp);
                currentLine = file.getNextLine();
            } while (currentLine != null);

            System.out.println("Number of employees: " + payroll.getNumberOfEmployees());
            System.out.println("\n---Employees first to last---");
            for (Employee e : payroll.getEmployeesFirstToLast()) {
                System.out.println(e);
            }

            System.out.println("\n---Employees last to first---");
            for (Employee e : payroll.getEmployeesLastToFirst()) {
                System.out.println(e);
            }

            System.out.println("\nEmployees with tenure greater than 4: " + payroll.getNumberOfTenureAbove(4));

        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
