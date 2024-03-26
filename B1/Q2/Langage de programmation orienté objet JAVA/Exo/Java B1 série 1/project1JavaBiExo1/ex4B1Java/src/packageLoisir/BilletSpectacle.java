package packageLoisir;

public class BilletSpectacle {
    String intituleSpectacle;
    String dateSpectacle;
    char categorie;
    double coutDeBase;
    boolean avecCarteEtudiant;

    BilletSpectacle(String intituleSpectacle,String dateSpectacle,char categorie,double coutDeBase,boolean avecCarteEtudiant){
        this.intituleSpectacle = intituleSpectacle;
        this.dateSpectacle = dateSpectacle;
        this.categorie = categorie;
        this.coutDeBase = coutDeBase;
        this.avecCarteEtudiant = avecCarteEtudiant;
    }

    public double prixBillet(){
        double prixBillet = coutDeBase;

        if(this.categorie == 'A'){
            prixBillet *= 1.10;
        } else if (this.categorie == 'B'){
            prixBillet *= 0.80;
        }
        if(this.avecCarteEtudiant){
            prixBillet /= 2;
        }

        return Math.round(prixBillet*100.0)/100.0;
    }

    String descriptionBillet(){
        return "Billet pour le spectacle intitulé " + this.intituleSpectacle + " du "
                + this.dateSpectacle + " en categorie " + this.categorie +
                ((this.avecCarteEtudiant) ? " avec carte étudiant" : "") + " pour un total de "
                + this.prixBillet() + " euros";
    }
}
