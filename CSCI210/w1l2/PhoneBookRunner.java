public class PhoneBookRunner {
    public static void main(String[] args) {

        System.out.println("Code by Raj Pabari");

        PhoneBook phoneBook = new PhoneBook();

        phoneBook.setNameAndPhone("Abe", "123-45678");
        phoneBook.setNameAndPhone("Bell", "234-5678");
        phoneBook.setNameAndPhone("Johnny", "345-67890");

        String[] names = { "Abe", "Bell", "Johnny" };

        for (String name : names) {
            System.out.println(name + ": " + phoneBook.getPhone(name));
        }

    }
}