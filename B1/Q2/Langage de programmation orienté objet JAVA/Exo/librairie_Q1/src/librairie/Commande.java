package librairie;

public class Commande {

    private double montantAcompte;
    private Livre livre;
    private Etudiant etudiant;


    Commande(double montantAcompte,Livre livre, Etudiant etudiant){
        this.montantAcompte = montantAcompte;
        this.livre = livre;
        this.etudiant = etudiant;
    }

    public double montantCommande(){
        double montant = livre.getCoutBase();

        if(etudiant.getBoursier()){
            montant -= livre.getReductionBoursier();
        }

        return montant;
    }

    public double soldeAPayer(){
        return montantCommande() - this.montantAcompte;
    }

    public String toString(){

    }
}
