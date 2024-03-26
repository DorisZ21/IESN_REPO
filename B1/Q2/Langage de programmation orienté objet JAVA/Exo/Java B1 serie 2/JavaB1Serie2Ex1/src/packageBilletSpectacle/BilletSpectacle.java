package packageBilletSpectacle;

public class BilletSpectacle {
    private String intituleSpectacle;
    private String dateSpectacle;
    private String categorie;
    private double coutDeBase;
    private boolean avecCarteEtudiant;

    public BilletSpectacle(String intituleSpectacle, String dateSpectacle, String categorie, double coutDeBase, boolean avecCarteEtudiant){
        setIntituleSpectacle(intituleSpectacle);
        setDateSpectacle(dateSpectacle);
        setCategorie(categorie);
        setCoutDeBase(coutDeBase);
        setAvecCarteEtudiant(avecCarteEtudiant);
    }

    public String getIntituleSpectacle(){
        return this.intituleSpectacle;
    }



}
