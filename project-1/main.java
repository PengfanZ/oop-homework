import java.util.*;

public class main {
    // initialization
    public static addressBook book = new addressBook();
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            String option = mainWindow();
            if (option.equals("4")) {
                break;
            }
            processOption(option);
        }
    }

    // return the choice of option
    public static String mainWindow() {
        System.out.println("\nMain Window: ");
        System.out.println("=============");
        System.out.println("Choose one of the following options:");
        System.out.println("(1) Add a new contact");
        System.out.println("(2) Search for contact");
        System.out.println("(3) Display all contacts");
        System.out.println("(4) Quit");

        String option = sc.nextLine();

        if (option.equals("1") || option.equals("2") || option.equals("3") || option.equals("4")) {
            return option;
        } else {
            return mainWindow();
        }
    }

    public static void processOption(String option) {
        if (option.equals("1")) {
            addContactWindow();
        } else if (option.equals("2")) {
            searchForContactWindow();
        } else {
            displayAllContacts();
        }
    }

    public static void addContactWindow() {
        System.out.println("\nMain Window --> Add a new contact window: (Enter the following information)");
        System.out.println("===========================================================================");
        System.out.print("Name: ");
        String name = sc.nextLine();
        System.out.print("Email: ");
        String email = sc.nextLine();
        System.out.print("Phone: ");
        String phone = sc.nextLine();
        System.out.print("Notes: ");
        String notes = sc.nextLine();

        book.addNewContact(name, email, phone, notes);

        System.out.println("---------------------------------------------------------------------------");
        System.out.println("Saved successfully....Press any key to go back to the Main Window");
        pressAnyKey();
    }

    public static void displayAllContacts() {
        System.out.println("\nMain Window --> Display All Contacts");
        System.out.println("====================================");
        printTableHeader();
        book.getAllContacts();
        System.out.println(
                "---------------------------------------------------------------------------------------------------------");
        System.out.println("Press any key to go back to the Main Window");
        pressAnyKey();
    }

    public static void searchForContactWindow() {
        System.out.println("\nMain Window --> Search for Contact window: (Choose one of the following options)");
        System.out.println("================================================================================");
        System.out.println("(1) Search by Name");
        System.out.println("(2) Search by Email");
        System.out.println("(3) Search by Phone \n");
        System.out.print("Enter your choice: ");
        String option = sc.nextLine();
        if (option.equals("1")) {
            searchByName();
        } else if (option.equals("2")) {
            searchByEmail();
        } else if (option.equals("3")) {
            searchByPhone();
        } else {
            searchForContactWindow();
        }
    }

    public static void searchByName() {
        System.out.println("\nMain Window --> Search for Contact window --> Search by Name");
        System.out.println("============================================================");
        System.out.print("(1) Enter Name: ");
        String name = sc.nextLine();
        printTableHeader();
        book.searchByName(name);
        System.out.println(
                "--------------------------------------------------------------------------------------------------------- \n");
        deleteOptions("Name");
    }

    public static void searchByEmail() {
        System.out.println("\nMain Window --> Search for Contact window --> Search by Email");
        System.out.println("============================================================");
        System.out.print("(2) Enter Email: ");
        String email = sc.nextLine();
        printTableHeader();
        book.searchByEmail(email);
        System.out.println(
                "--------------------------------------------------------------------------------------------------------- \n");
        deleteOptions("Email");
    }

    public static void searchByPhone() {
        System.out.println("\nMain Window --> Search for Contact window --> Search by Phone");
        System.out.println("============================================================");
        System.out.print("(3) Enter Phone: ");
        String phone = sc.nextLine();
        printTableHeader();
        book.searchByPhone(phone);
        System.out.println(
                "--------------------------------------------------------------------------------------------------------- \n");
        deleteOptions("Phone");
    }

    public static void deleteOptions(String searchingOption) {
        System.out.println("\nChoose one of these options: ");
        System.out.println("(1) To delete a contact");
        System.out.println("(2) Back to main Window");
        System.out.print("Enter Your Choice: ");
        String option = sc.nextLine();
        if (option.equals("1")) {
            deleteContact(searchingOption);
        } else if (option.equals("2")) {
            return;
        } else {
            deleteOptions(searchingOption);
        }
    }

    public static void deleteContact(String searchingOption) {
        System.out.println("\nMain Window --> Search for Contact window --> Search by " + searchingOption
                + " --> Delete a Contact");
        System.out.println("============================");
        System.out.print("Enter the Contact ID: ");
        String id = sc.nextLine();
        if (book.deleteContact(id)) {
            System.out.println("Deleted....press any key to go back to the main window");
        } else {
            System.out.println("The id does not exist....press any key to go back to the main window");
        }
        pressAnyKey();
    }

    // helper function
    public static void pressAnyKey() {
        String anykey = sc.nextLine();
        if (anykey != null) {
            return;
        }
    }

    public static void printTableHeader() {
        System.out.println(
                "---------------------------------------------------------------------------------------------------------");
        System.out.println(
                "ID | Name                  | Email                 | Phone                  | Notes                      ");
        System.out.println(
                "---------------------------------------------------------------------------------------------------------");
    }
}
