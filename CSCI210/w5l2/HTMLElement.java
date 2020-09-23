public class HTMLElement {
    public String nameStart;
    public String nameEnd;
    public Tag tagStart;
    public Tag tagEnd;

    public HTMLElement(String start, String end, Tag tag_start, Tag tag_end) {
        nameStart = start;
        nameEnd = end;
        tagStart = tag_start;
        tagEnd = tag_end;
    }

}