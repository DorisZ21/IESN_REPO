package sweetHome;

public class VillaAvecCave extends Villa {
    private double surfaceCave;
    private boolean aGarageEnSousSol;

    VillaAvecCave(String adresse, int nbChambres, int nbEtages,
                  double surfaceRezChaussee,double surfaceHabitableEtages,
                  double superficieTerrain, double surfaceCave,
                  boolean aGarageEnSousSol){
        super(adresse,nbChambres,nbEtages,surfaceRezChaussee,surfaceHabitableEtages,superficieTerrain);
        this.surfaceCave = surfaceCave;
        this.aGarageEnSousSol = aGarageEnSousSol;
    }

    public int nbNiveaux(){
        return getNbEtages() + 2;
    }

    @Override
    public double surfaceTotale(){
        return super.surfaceTotale() + this.surfaceCave;
    }

    @Override
    public String toString(){
        return super.toString() + " Elle comporte " + nbNiveaux()
                + " niveaux" + " et contient des caves de " + this.surfaceCave + " m2"
                + ((this.aGarageEnSousSol) ? " avec" : " sans") + " garage(s) en sous-sol.";
    }
}
