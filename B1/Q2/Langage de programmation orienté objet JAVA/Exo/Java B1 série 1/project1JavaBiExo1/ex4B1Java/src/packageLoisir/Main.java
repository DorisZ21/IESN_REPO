package packageLoisir;

public class Main {
    public static void main(String[] args) {
        BilletSpectacle billet1 = new BilletSpectacle("Les Misérables","12/12/2020",'A',55.26,true);
        BilletSpectacle billet2 = new BilletSpectacle("Les Misérables","12/12/2020",'B',50.0,true);
        BilletSpectacle billet3 = new BilletSpectacle("Les Misérables","12/12/2020",'A',50.0,false);

        System.out.println(billet1.descriptionBillet());
        System.out.println("\n");
        System.out.println(billet2.descriptionBillet());
        System.out.println("\n");
        System.out.println(billet3.descriptionBillet());
    }
}