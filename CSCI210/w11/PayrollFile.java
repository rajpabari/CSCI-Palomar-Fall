import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.List;

public class PayrollFile {
    private List<String> fileContents;
    private int currentIndex;

    public PayrollFile(String filePath) throws IOException {
        currentIndex = 0;
        fileContents = Files.readAllLines(Paths.get(filePath));
    }

    public String getNextLine() {
        try {
            return fileContents.get(currentIndex++);
        } catch (Exception e) {
            return null;
        }

    }
}
