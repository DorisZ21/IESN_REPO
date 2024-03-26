package packageIndividu;

public class Individu {
    private String prenom;
    private int age;
    private char genre;
    private String localite;

    public Individu(String prenom, int age, char genre, String localite){
        setPrenom(prenom);
        setAge(age);
        setGenre(genre);
        setLocalite(localite);
    }

    public String getPrenom(){
        return this.prenom;
    }

    public int getAge(){
        return this.age;
    }

    public char getGenre(){
        return this.genre;
    }

    public String getLocalite(){
        return this.localite;
    }

    public void setPrenom(String prenom){
        if(prenom != null){
            this.prenom = prenom;
        }
    }

    public void setAge(int age){
        if(age >= 0 && age <= 120){
            this.age = age;
        }
    }

    public void setGenre(char genre){
        if(genre == 'M' || genre == 'F' || genre == 'X'){
            this.genre = genre;
        } else if (this.genre == '\u0000'){
            this.genre = 'X';
        }
    }

    public void setLocalite(String localite){
        if(localite != null){
            this.localite = localite;
        }
    }

    public String presentation(){
        return "Je m'appelle " + this.prenom + " et j'ai " + this.age + " ans. Je suis de sexe " + this.genre + " et j'habite à " + this.localite + ".";
    }

    public String presentation(int codeLangue){
        if(codeLangue == 1){
            return presentation();
        } else if (codeLangue == 2) {
           return "My firstname is " + this.prenom + " and I am " + this.age + " years old. I live in " + this.localite;
        }else if(codeLangue == 3){
            return "Ik heet " + this.prenom + " en ik ben " + this.age + " jaar oud. Ik woon in " + this.localite;
        }else{
            return "";
        }
    }

}
