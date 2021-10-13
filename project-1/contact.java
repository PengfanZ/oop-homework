
public class contact {
    private String name;
    private String email;
    private String phone;
    private String notes;
    private int id;
    // private static int id = 0;

    public contact() {
        this.name = "";
        this.email = "";
        this.phone = "";
        this.notes = "";
        this.id = -1;
    }

    public void addName(String name) {
        this.name = name;
    }

    public void addEmail(String email) {
        this.email = email;
    }

    public void addPhone(String phone) {
        this.phone = phone;
    }

    public void addNotes(String notes) {
        this.notes = notes;
    }

    public void addId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getPhone() {
        return phone;
    }

    public String getNotes() {
        return notes;
    }

    public int getId() {
        return id;
    }
}