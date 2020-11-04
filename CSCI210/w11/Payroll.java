import java.util.NoSuchElementException;

public class Payroll {
    private LinkedList<Employee> payroll;
    private int numEmployees;

    public Payroll() {
        payroll = new LinkedList<Employee>();
        numEmployees = 0;
    }

    public void addEmployee(Employee e) {
        payroll.insertAtBack(e);
        numEmployees++;
    }

    public int getNumberOfEmployees() {
        return numEmployees;
    }

    public Employee[] getEmployeesFirstToLast() {
        Employee[] emps = new Employee[numEmployees];
        for (int i = 0; i < numEmployees; i++) {
            try {
                emps[i] = payroll.removeFromFront();
                payroll.insertAtBack(emps[i]);
            } catch (NoSuchElementException e) {
                break;
            }
        }
        return emps;
    }

    public Employee[] getEmployeesLastToFirst() {
        Employee[] emps = new Employee[numEmployees];
        for (int i = 0; i < numEmployees; i++) {
            try {
                emps[i] = payroll.removeFromBack();
                payroll.insertAtFront(emps[i]);
            } catch (NoSuchElementException e) {
                break;
            }
        }
        return emps;
    }

    public int getNumberOfTenureAbove(int above) {
        Employee[] emps = getEmployeesFirstToLast();
        int numberOfTenureAbove = 0;
        for (int i = 0; i < emps.length; i++) {
            if (emps[i].getTenure() > above)
                numberOfTenureAbove++;
        }
        return numberOfTenureAbove;
    }
}
