import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.List;
import java.util.Stack;

import java.util.ArrayList;

class HTMLValidatorRunner {
    /*
     * Features Added since video: 
     * -handle whitespace 
     * -handle html tags on same line
     * -handle text between html tags
     * -prevented popping from empty stack
     * 
     * TODO:
     * -add support for more html tags
     * NOTE: for scale, i don't think that the enum is the right way to go here
     * instead, constructor should be new HTMLElement(String tagName)
     * -make member variables in HTMLElement private, make getter and setter methods
     */

    private static HTMLElement[] htmlElements = { new HTMLElement("<html>", "</html>", Tag.HTMLSTART, Tag.HTMLEND),
            new HTMLElement("<head>", "</head>", Tag.HEADSTART, Tag.HEADEND),
            new HTMLElement("<body>", "</body>", Tag.BODYSTART, Tag.BODYEND),
            new HTMLElement("<title>", "</title>", Tag.TITLESTART, Tag.TITLEEND),
            new HTMLElement("<p>", "</p>", Tag.PARASTART, Tag.PARAEND),

    };

    public static String title() {
        return "HTML Validator\n" + "Version 0.0.2\n" + "Code by Raj Pabari\n";
    }

    public static String usage() {
        return "Usage info\n" + "Enter HTML filename\n" + "Example: java Main index.html";
    }

    public static void parse(List<String> html) {
        Stack<Tag> stack = new Stack<Tag>();

        for (String s : html) {
            System.out.print("Checking " + s);
            for (HTMLElement e : htmlElements) {
                if (s.trim().equals(e.nameStart)) {
                    System.out.print(" -push- (" + e.tagStart + ")");
                    stack.push(e.tagStart);
                    // after you've found the corresponding element,
                    // there's no need to keep checking
                    break;
                } else if (s.trim().equals(e.nameEnd)) {
                    if (stack.empty()) { // to avoid popping an empty stack
                        System.out.println("\nHTML Invalid");
                        System.exit(0);
                    }
                    Tag tag = stack.pop();
                    System.out.print(" -pop- (" + tag + ")");
                    if (tag != e.tagStart) {
                        System.out.println("\nHTML Invalid");
                        System.exit(0);
                    }
                }
            }
            System.out.println("");
        }

        if (stack.empty()) {
            System.out.println("HTML Valid");
        } else
            System.out.println("HTML Invalid");
    }

    public static void main(String[] args) {
        System.out.println(title());
        if (args.length == 0) {
            System.out.println(usage());
            System.exit(0);
        }

        try {
            List<String> html = Files.readAllLines(Paths.get(args[0]));

            // handle text between tags and same line tags and whitespace
            List<String> betterHTML = new ArrayList<String>();
            for (String i : html) {

                // using custom delimiter to preserve the <> in html tags
                // otherwise, there's no way to distinguish between html tag and normal text
                // also, this removes whitespace without calling string.trim()
                // NOTE: using & as delimiter because it is not valid html, it would be &amp;
                i = i.replace("<", "&<");
                i = i.replace(">", ">&");
                for (String j : i.split("&")) {
                    // ensure that it is really an html tag, not an &amp;
                    if (j.contains("<") && j.contains(">"))
                        betterHTML.add(j);
                }

            }
            System.out.println(betterHTML);
            parse(betterHTML);
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }
    }
}