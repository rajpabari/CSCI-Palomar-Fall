public class DerRunner {
    public static void main(String[] args) {
        run(args);
    }

    public static boolean run(String[] args) {
        try {
            DerCli derCli = new DerCli(args);
            return true;
        } catch (Exception e) {
            System.out.println(getError(e));
            return false;
        }
    }

    public static String getError(Exception e) {
        return e.toString();
    }
}
