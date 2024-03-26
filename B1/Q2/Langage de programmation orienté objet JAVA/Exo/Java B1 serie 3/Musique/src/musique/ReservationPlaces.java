package musique;

public class ReservationPlaces {
    private int nbPlaces;
    private boolean estPaye;
    private Personne personne;
    private Concert concert;

    ReservationPlaces(int nbPlaces,boolean estPaye, Personne personne, Concert concert){
        setNbPlaces(nbPlaces);
        this.estPaye = estPaye;
        this.personne = personne;
        this.concert = concert;
    }
    // Surcharge des constructeurs

    ReservationPlaces(boolean estPaye,Personne personne, Concert concert){
        this(1,estPaye,personne,concert);
    }

    ReservationPlaces(int nbPlaces,Personne personne, Concert concert){
        this(nbPlaces,true,personne,concert);
    }

    ReservationPlaces(Personne personne,Concert concert){
        this(1,true,personne,concert);
    }

    public void setNbPlaces(int nbPlaces){
        if(nbPlaces < 0){
            this.nbPlaces = 1;
        }else {
            this.nbPlaces = nbPlaces;
        }
    }

    public double prixTotal(){
        return nbPlaces * concert.getPrix();
    }

    public String toString(){
        return personne + " a réservé " + this.nbPlaces + " places pour " + concert +
                " pour un coût total de " + prixTotal() + " euros\n" + "Cette réservation est " +
                ((estPaye) ? "payé" : "en attente de paiment.");
    }
}
