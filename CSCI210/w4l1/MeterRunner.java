public class MeterRunner {

    private static boolean m_verbose;
    private static boolean m_json;

    private static void usage() {
        System.out.println("Usage Info:");
        System.out.println("--version");
        System.out.println("--verbose");
        System.out.println("--json");
    }

    private static void version() {
        System.out.println("Version 0.0.0");
    }

    // CLI = command line interface
    private static void doCLIArgs(String[] args) {
        System.out.println("args.length = " + args.length);
        for (String s : args) {
            // System.out.println(s);
            // parse command-line args

            if (s.equals("--version")) {
                version();
                System.exit(42);
            }
            if (s.equals("--verbose")) {
                m_verbose = true;
                System.out.println("Running in verbose mode");
            } else if (s.equals("--json")) {
                m_json = true;
            } else {
                usage();
                System.exit(43);
            }
        }

    }

    public static void main(String[] args) {

        System.out.println("Meter tool");
        System.out.println("Code by Raj Pabari");

        if (args.length == 0) {
            usage();
            return;
        }

        doCLIArgs(args);
    }
}
