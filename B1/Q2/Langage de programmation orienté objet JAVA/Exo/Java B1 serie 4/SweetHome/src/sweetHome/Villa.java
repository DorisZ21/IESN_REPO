package sweetHome;

public class Villa {
    private String adresse;
    private int nbChambres;
    private int nbEtages;
    private double surfaceRezChaussee;
    private double surfaceHabitableEtages;
    private double superficieTerrain;

    Villa(String adresse,int nbChambres,int nbEtages,double surfaceRezChaussee, double surfaceHabitableEtages, double superficieTerrain){
        this.adresse = adresse;
        this.nbChambres = nbChambres;
        this.nbEtages = nbEtages;
        this.surfaceRezChaussee = surfaceRezChaussee;
        setSurfaceHabitableEtages(surfaceHabitableEtages);
        this.superficieTerrain = superficieTerrain;
    }

    Villa(String adresse,int nbChambres, double surfaceRezChaussee, double superficieTerrain){
        this(adresse,nbChambres,0,surfaceRezChaussee,0,superficieTerrain);
    }

    public int getNbEtages(){
        return this.nbEtages;
    }

    public void setSurfaceHabitableEtages(double surfaceHabitableEtages){
        if(this.nbEtages < 1){
            this.surfaceHabitableEtages = 0;
        }else{
            this.surfaceHabitableEtages = surfaceHabitableEtages;
        }
    }

    public double surfaceTotale(){
        return this.surfaceRezChaussee + this.surfaceHabitableEtages;
    }

    public double superficieJardin(){
        return (this.superficieTerrain - this.surfaceRezChaussee) / 100;
    }

    public String typeJardin(){
        String typeJardin;
        double superficieJardin = superficieJardin();
        if(superficieJardin <= 0){
            typeJardin = "Sans jardin";
        } else if (superficieJardin < 50) {
            typeJardin = "Avec jardin de " + superficieJardin + " ares.";
        }else{
            typeJardin = "Avec parc de " + superficieJardin + " ares";
        }

        return typeJardin;
    }

    public boolean pourFamilleNombreuse(){
        boolean pourFamilleNombreuse = true;
        if(this.nbChambres < 4){
            pourFamilleNombreuse = false;
        }
        return pourFamilleNombreuse;
    }

    public String toString(){
        return "La villa située au " + this.adresse + " d'une surface habitable de " + surfaceTotale() + " m2"
                + ((pourFamilleNombreuse()) ? " convient" : " ne convient pas") + " pour une famille nombreuse";
    }
}
