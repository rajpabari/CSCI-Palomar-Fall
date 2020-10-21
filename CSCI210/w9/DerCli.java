import java.util.Queue;
import java.util.LinkedList;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class DerCli {
    private ArrayList<DerApi> derApiArray;
    private String[] args;
    private Queue<String> taskQueue;
    private Queue<Thread> threadQueue;
    private int totalQueueLength;
    private Scanner scan;

    public DerCli(String[] cliStrings) throws IOException {
        derApiArray = new ArrayList<DerApi>();
        args = cliStrings;
        totalQueueLength = 0;
        taskQueue = new LinkedList<String>();
        threadQueue = new LinkedList<Thread>();
        scan = new Scanner(System.in);
        info();
        doArgs();
    }

    private void info() {
        System.out.println("DER Tool 0.1.0\nCode by Raj Pabari");
    }

    private void doArgs() throws IOException {
        if (args.length == 0) {
            usage();
            return;
        }
        for (int i = 0; i < args.length; i++) {
            if (args[i].length() <= 1)
                continue;
            if (args[i].substring(0, 2).equals("--")) {
                findAction(args, i);
            }
        }
    }

    private void findAction(String[] array, int index) throws IOException {
        switch (array[index]) {
            case "--cli":
                runCLIMode();
                break;
            case "--add":
                addToQueue(array[index + 1], Integer.parseInt(array[index + 2].strip()));
                break;
            case "--wh-delivered":
                whDelivered();
                break;
            case "--wh-received":
                whReceived();
                break;
            case "--certs":
                showCerts();
                break;
            case "--LFDIs":
                showLFDIS();
                break;
            case "--ip":
                showIp();
                break;
            case "--file":
                addToQueueFromFile(array[index + 1]);
                break;
            case "--status":
                showStatuses();
                break;
            default:
            case "--help":
                usage();
        }
    }

    private void showStatuses() {
        if (derApiArray.size() == 0 && taskQueue.isEmpty()) {
            System.out.println("Nothing in array/queue to show the status of. May only be used in CLI mode");
            return;
        }
        System.out.println("Currently Active:");
        for (DerApi i : derApiArray) {
            System.out.println("DerAPI id " + i.getID());
        }

        System.out.println("In queue:");
        for (String i : taskQueue) {
            System.out.println("DerAPI id " + i);
        }

    }

    private void showIp() {
        if (derApiArray.size() == 0) {
            System.out.println("No Ip addresses to show because no DERs added. Please add a DER first");
            return;
        }
        for (int i = 0; i < derApiArray.size(); i++) {
            System.out.println(
                    "DerApi ID " + derApiArray.get(i).getID() + " IP Address: " + derApiArray.get(i).getIpAddr());
        }
    }

    private void showLFDIS() {
        if (derApiArray.size() == 0) {
            System.out.println("No LFDIS to show because no DERs added. Please add a DER first");
            return;
        }
        String[] currentLFDI;
        for (DerApi i : derApiArray) {
            System.out.print("DerApi id " + i.getID() + " ");
            currentLFDI = i.getLFDIs();
            for (String j : currentLFDI) {
                System.out.print(j);
            }
            System.out.print("\n");
        }
    }

    private void whDelivered() {
        if (derApiArray.size() == 0) {
            System.out.println("No WH Delivered to show because no DERs added. Please add a DER first");
            return;
        }
        for (int i = 0; i < derApiArray.size(); i++) {
            System.out.println("DerApi ID " + derApiArray.get(i).getID() + " WH Delivered: "
                    + derApiArray.get(i).getWattHoursDelivered());
        }
    }

    private void whReceived() {
        if (derApiArray.size() == 0) {
            System.out.println("No Watt Hours Received to show because no DERs added. Please add a DER first");
            return;
        }
        for (int i = 0; i < derApiArray.size(); i++) {
            System.out.println("DerApi ID " + derApiArray.get(i).getID() + " WH Received: "
                    + derApiArray.get(i).getWattHoursReceived());
        }
    }

    private void showCerts() {
        byte[] toPrint;
        DerApi temp = new DerApi();
        for (int i = 0; i < CertType.values().length - 1; i++) {
            System.out.print("CertType " + CertType.values()[i] + ": ");
            toPrint = temp.getCert(CertType.values()[i]);
            for (int j = 0; j < toPrint.length; j++) {
                System.out.print(toPrint[j] + " ");
            }
            System.out.print("\n");
        }
    }

    private void addToQueueFromFile(String filename) throws IOException {
        List<String> file = Files.readAllLines(Paths.get(filename));
        String[] currentLine;
        for (int i = 1; i < file.size(); i++) {
            currentLine = file.get(i).split(",");
            addToQueue(currentLine[0].strip(), Integer.parseInt(currentLine[1].strip()));
        }
    }

    private void addToQueue(String id, int time) {
        System.out.print("Sending client " + id + " to queue. Wait time " + totalQueueLength);
        totalQueueLength += time;
        taskQueue.add(id);
        System.out.print(" " + taskQueue + "\n");
        Runnable addDerToArray = new Runnable() {
            public void run() {
                try {
                    Thread.sleep(time * 1000);
                } catch (InterruptedException e) {
                    System.out.println(e);
                    return;
                }
                derApiArray.add(new DerApi(id));
                taskQueue.remove();
                threadQueue.remove();
                System.out.print("\n" + id + " successfully dequeued\ncmd> ");
                if (!threadQueue.isEmpty()) {
                    threadQueue.peek().start();
                }
            }
        };
        Thread thread = new Thread(addDerToArray);
        if (threadQueue.isEmpty()) {
            threadQueue.add(thread);
            threadQueue.peek().start();
        } else {
            threadQueue.add(thread);
        }
    }

    private void runCLIMode() throws IOException {
        System.out.println("ENTER \"quit\" to end CLI mode");
        String input;
        String[] CLIArgs;
        while (true) {
            System.out.print("cmd> ");
            input = scan.nextLine();
            CLIArgs = input.split(" ");
            if (CLIArgs[0].equalsIgnoreCase("quit"))
                break;
            CLIArgs[0] = "--" + CLIArgs[0];
            findAction(CLIArgs, 0);
        }
    }

    private void usage() {
        System.out.println("java Main (display Usage Info)\n" + "java Main --help (display Usage Info)\n"
                + "java Main --cli (startup in CLI mode, \"quit\" to exit CLI mode)\n"
                + "java Main --file FILENAME (read input from FILENAME)\n"
                + "java Main --wh-delivered (show watt hours delivered to the customer)\n"
                + "java Main --wh-received (show watt hours received from the customer - if using solar)\n"
                + "java Main --certs (show SERCA, MCA, MICA, and Device Certs)\n"
                + "java Main --LFDIs (show list of Long Form Device IDs)\n" + "java Main --ip  (show IP address)\n"
                + "java Main --add CLIENT-ID TIME-IN-SECS\n"
                + "java Main --status (display status of clients using the DER)");
    }
}
