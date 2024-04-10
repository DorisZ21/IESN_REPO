package librairie;

public class Doctorant extends Etudiant {

    private String titreThese;
    private String domaineRecherche;

    Doctorant(String prenomNom, String faculte,int numeroAnnee, boolean boursier, String titreThese, String domaineRecherche){
        super(prenomNom,faculte,"doctorat",numeroAnnee,boursier);
        this.titreThese = titreThese;
        this.domaineRecherche = domaineRecherche;
    }

    public String descriptionThese(){
        return this.titreThese + " " + getPrenomNom() + " " + this.domaineRecherche;
    }

    @Override
    public String toString(){
       return super.toString() + " Doctorant(e) en " + this.domaineRecherche;
    }
}
