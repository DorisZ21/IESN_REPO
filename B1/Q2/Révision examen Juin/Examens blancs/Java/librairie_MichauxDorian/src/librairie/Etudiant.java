package librairie;

public class Etudiant {
    private String prenomNom;
    private String faculte;
    private String cycle;
    private int numeroAnnee;
    private boolean boursier;

    Etudiant(String prenomNom, String faculte, String cycle, int numeroAnnee, boolean boursier){
        this.prenomNom = prenomNom;
        this.faculte = faculte;
        this.cycle = cycle;
        setNumeroAnnee(numeroAnnee);
        this.boursier = boursier;
    }

    Etudiant(String prenomNom,String faculte,String cycle, int numeroAnnee){
        this(prenomNom,faculte,cycle,numeroAnnee,false);
    }


    public String getPrenomNom(){
        return this.prenomNom;
    }

    public int getNumeroAnnee(){
       return  this.numeroAnnee;
    }

    public boolean getBoursier(){
        return this.boursier;
    }

    public void setFaculte(String faculte){
        this.faculte = faculte;
    }

    public void setNumeroAnnee(int numeroAnnee){
        if(numeroAnnee > 3){
            this.numeroAnnee = 3;
        }else if (numeroAnnee < 1){
            this.numeroAnnee = 1;
        }else{
            this.numeroAnnee = numeroAnnee;
        }
    }

    public String descriptionFormation(){
        return this.cycle + " " + this.numeroAnnee + " en " + this.faculte;
    }


    public String toString(){
            return this.prenomNom + " inscrit(e) en " + descriptionFormation()
                    + ((this.boursier) ? " bénéficiant d'une bourse" : "");
    }

}
