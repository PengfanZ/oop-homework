import java.util.*;

public class addressBook {
    private ArrayList<contact> contacts;
    private static int id = 1;

    public addressBook() {
        contacts = new ArrayList<>();
    }

    public void addNewContact(String name, String email, String phone, String notes) {
        contact person = new contact();
        person.addName(name);
        person.addEmail(email);
        person.addPhone(phone);
        person.addNotes(notes);
        person.addId(id++);

        contacts.add(person);
    }

    public void getAllContacts() {
        printAllContacts(contacts);
    }

    public void searchByName(String goal) {
        ArrayList<contact> results = new ArrayList<>();
        for (int i = 0; i < contacts.size(); i++) {
            contact person = contacts.get(i);
            String name = person.getName();
            if (name.contains(goal)) {
                results.add(person);
            }
        }

        printAllContacts(results);
    }

    public void searchByEmail(String goal) {
        ArrayList<contact> results = new ArrayList<>();
        for (int i = 0; i < contacts.size(); i++) {
            contact person = contacts.get(i);
            String email = person.getEmail();
            if (email.contains(goal)) {
                results.add(person);
            }
        }

        printAllContacts(results);
    }

    public void searchByPhone(String goal) {
        ArrayList<contact> results = new ArrayList<>();
        for (int i = 0; i < contacts.size(); i++) {
            contact person = contacts.get(i);
            String phone = person.getPhone();
            if (phone.contains(goal)) {
                results.add(person);
            }
        }

        printAllContacts(results);
    }

    public void printAllContacts(ArrayList<contact> results) {
        for (int i = 0; i < results.size(); i++) {
            String contactId = String.valueOf(results.get(i).getId());
            String name = results.get(i).getName();
            String email = results.get(i).getEmail();
            String phone = results.get(i).getPhone();
            String notes = results.get(i).getNotes();

            System.out.printf("%-2s |", contactId);
            System.out.printf(" %-21s |", name);
            System.out.printf(" %-21s |", email);
            System.out.printf(" %-22s |", phone);
            System.out.printf(" %s ", notes);
            System.out.println("\n");
        }
    }

    public boolean deleteContact(String id) {
        for (int i = 0; i < contacts.size(); i++) {
            String contactId = String.valueOf(contacts.get(i).getId());
            if (contactId.equals(id)) {
                contacts.remove(i);
                return true;
            }
        }
        return false;
    }
}
