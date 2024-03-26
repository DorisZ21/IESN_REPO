package packageLoisir;

public class SejourDisney {
    int nbEnfants;
    int nbAdultes;
    int nbJours;
    int nbVehiculesParking;
    boolean avecPMR;

    public SejourDisney(int nbEnfants, int nbAdultes, int nbJours, int nbVehiculesParking, boolean avecPMR) {
        this.nbEnfants = nbEnfants;
        this.nbAdultes = nbAdultes;
        this.nbJours = nbJours;
        this.nbVehiculesParking = nbVehiculesParking;
        this.avecPMR = avecPMR;
    }

    public boolean estLongSejour() {
        return nbJours - 1 > 3;
    }

    public double coutEntreeParc(){
        return (nbEnfants * 19.9 + nbAdultes * 45) * ((estLongSejour()) ? nbJours - 1 : nbJours);
    }

    public int nbNuiteesEnfantGratuites(){
        return (nbEnfants * nbJours - 1) / 2;
    }

    public double coutHotel(){
        return ((nbEnfants * 49.9) * ((nbJours - 1) - nbNuiteesEnfantGratuites()) + ((nbAdultes * 65.5) * nbJours - 1));
    }

    public int coutParking(){
        return ((avecPMR) ? 0 : (nbVehiculesParking * 8)*nbJours);
    }

    public double coutTotal(){
        return coutEntreeParc() + coutHotel() + coutParking();
    }


}
