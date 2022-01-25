public class PhoneBook implements FastLookup {

    private PhoneBookEntry[] bucket = new PhoneBookEntry[16];

    private int getHash(String name) {
        return name.length();
    }

    public void setNameAndPhone(String name, String phone) {
        PhoneBookEntry obj = new PhoneBookEntry(name, phone);

        int hash = getHash(name);

        System.out.printf("%s - %s - %d%n", name, phone, hash);

        bucket[hash] = obj;
    }

    public String getPhone(String name) {
        PhoneBookEntry obj = bucket[getHash(name)];
        return obj.phone;
    }
}