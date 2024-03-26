package premierProjet;

public class Individu {
    String prenom;
    int age;
    char genre;
    String localite;

    Individu(String prenom,int age,char genre,String localite){
        this.prenom = prenom;
        this.age = age;
        this.genre = genre;
        this.localite = localite;
    }

    public String presentation(){
        return "Je m'appelle " + this.prenom + " et je suis âgé" + ((this.genre == 'F') ? 'e' : "")+ " de " + this.age + " an"+ ((this.age > 1) ? 's' : "")  + " Je réside à " + this.localite + ".";
    }


}
