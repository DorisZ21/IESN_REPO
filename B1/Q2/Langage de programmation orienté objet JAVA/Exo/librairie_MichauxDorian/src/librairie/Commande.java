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

    public Etudiant getEtudiant(){
        return this.etudiant;
    }

    public Livre getLivre(){
        return this.livre;
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

    public double soldeAPayer(int promotion){
        double montantRestant = montantCommande() - this.montantAcompte;
        double montantFinal = montantRestant - (((double)promotion / 100) * montantRestant);
        return montantFinal;
    }


    public String toString(){
        return this.etudiant + " a commandé " + this.livre + " "
                + ((this.montantAcompte > 0) ? " avec un accompte de " + this.montantAcompte + " euros" : "");
    }
}
