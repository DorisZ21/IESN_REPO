package musique;

public class Main {
    public static void main(String[] args) {
        GroupeMusical premierGroupe = new GroupeMusical("LesPoufs","Dorian", 1);
        System.out.println(premierGroupe);

        Concert ouvertureFestival = new Concert("Tumorow Land","21 janvier 2025","Andenne",14.5,premierGroupe);
        System.out.println(ouvertureFestival);
        System.out.println(ouvertureFestival.getGroupeMusical().getNomChanteur());


        Personne moi = new Personne("Dorian","Michaux","0493378771","dorian-michaux21@outlook.be");
        System.out.println(moi);

        ReservationPlaces premierReservation = new ReservationPlaces(2,true,moi,ouvertureFestival);
        System.out.println(premierReservation);
    }
}