package tournois;
import java.time.LocalDate;
public class Arbitre {

    private String prenom;
    private String nom;
    private String code;
    private int anneeNaissance;

    Arbitre(String prenom, String nom, String code, int anneeNaissance){
        this.prenom = prenom;
        this.nom = nom;
        this.code = code;
        setAnneeNaissance(anneeNaissance);
    }

    public void setAnneeNaissance(int anneeNaissance){
        LocalDate dateDuJour = LocalDate.now();
        int anneeDujour = dateDuJour.getYear();
        int age = anneeDujour - anneeNaissance;

        if(age < 18){
            this.anneeNaissance = anneeDujour - 18;
        }else {
            this.anneeNaissance = anneeNaissance;
        }
    }

    public String matricule(){
        return this.anneeNaissance + this.code;
    }

    public String toString(){
        return this.prenom + " " + this.nom + " matricule : " + matricule();
    }

}
