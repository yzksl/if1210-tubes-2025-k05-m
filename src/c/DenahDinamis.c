#include "../header/DenahDinamis.h"
#include "../header/GlobalVariable.h"

void ubahDenah(){
    int newRow, newColumn;
    Point bisaUbahDenah={-1, -1, 1};
    scanf(" %d %d", &newRow, &newColumn);

    if (newRow>26 || newColumn>26) {
        printf("Banyak baris atau kolom tidak boleh lebih dari 26\n");
        return;
    }
    
    if (newColumn<globalDenahRumahSakit.nColumn){
        int tempRow = (newRow<globalDenahRumahSakit.nRow) ? newRow : globalDenahRumahSakit.nRow;
        for (int row=0; row<tempRow; row++){
            for (int column=newColumn; column<globalDenahRumahSakit.nColumn; column++){
                if (globalDenahRumahSakit.Ruangan[row][column].idDokter!=0){
                    Point temp={row, column, 0};
                    bisaUbahDenah = temp;
                    break;
                }
            }
            if (!bisaUbahDenah.antrian) break;
        }
    }
    
    if (newRow<globalDenahRumahSakit.nRow && bisaUbahDenah.antrian){
        for (int row=newRow; row<globalDenahRumahSakit.nRow; row++){
            for (int column=0; column<globalDenahRumahSakit.nColumn; column++){
                if (globalDenahRumahSakit.Ruangan[row][column].idDokter!=0){
                    Point temp={row, column, 0};
                    bisaUbahDenah = temp;
                    break;
                }
            }
            if (!bisaUbahDenah.antrian) break;
        }
    }
    
    if (!bisaUbahDenah.antrian){
        printf("Tidak dapat mengubah ukuran denah. Ruangan %c%d masih ditempati oleh Dr. %s. Silakan pindahkan dokter terlebih dahulu.\n", bisaUbahDenah.row+'A', bisaUbahDenah.column+1, getAccountName(globalDenahRumahSakit.Ruangan[bisaUbahDenah.row][bisaUbahDenah.column].idDokter, DATA_TYPE_DOCTOR));
        return;
    }
    
    if (newColumn<globalDenahRumahSakit.nColumn){
        int tempRow = (newRow<globalDenahRumahSakit.nRow) ? newRow : globalDenahRumahSakit.nRow;
        for (int row=0; row<tempRow; row++){
            for (int column=newColumn; column<globalDenahRumahSakit.nColumn; column++){
                freeQueue(&globalDenahRumahSakit.Ruangan[row][column].idAntrian);
            }
        }
    }
    
    if (newRow<globalDenahRumahSakit.nRow){
        for (int row=newRow; row<globalDenahRumahSakit.nRow; row++){
            for (int column=0; column<globalDenahRumahSakit.nColumn; column++){
                freeQueue(&globalDenahRumahSakit.Ruangan[row][column].idAntrian);
            }
        }
    }
    
    if (newColumn>globalDenahRumahSakit.nColumn){
        int tempRow = (newRow<globalDenahRumahSakit.nRow) ? newRow : globalDenahRumahSakit.nRow;
        for (int row=0; row<tempRow; row++){
            for (int column=globalDenahRumahSakit.nColumn; column<newColumn; column++){
                createQueue(&globalDenahRumahSakit.Ruangan[row][column].idAntrian, globalDenahRumahSakit.kapasitasAntrian+globalDenahRumahSakit.kapasitasRuangan);
            }
        }
    }
    
    if (newRow>globalDenahRumahSakit.nRow){
        for (int row=globalDenahRumahSakit.nRow; row<newRow; row++){
            for (int column=0; column<newColumn; column++){
                createQueue(&globalDenahRumahSakit.Ruangan[row][column].idAntrian, globalDenahRumahSakit.kapasitasAntrian+globalDenahRumahSakit.kapasitasRuangan);
            }
        }
    }
    
    globalDenahRumahSakit.nRow=newRow;
    globalDenahRumahSakit.nColumn=newColumn;

}

void pindahDokter(){
    char ruanganLama[256], ruanganBaru[256];
    scanf(" %s %s", ruanganLama, ruanganBaru);

    int rowLama, columnLama, rowBaru, columnBaru;
    kodeRuanganKonverter(ruanganLama, &rowLama, &columnLama);
    kodeRuanganKonverter(ruanganBaru, &rowBaru, &columnBaru);

    if(globalDenahRumahSakit.Ruangan[rowLama][columnLama].idDokter==0){
        printf("Pemindahan gagal. Ruangan %c%d Kosong.\n", rowLama+'A', columnLama+1);
        return;
    }
    if(globalDenahRumahSakit.Ruangan[rowBaru][columnBaru].idDokter!=0){
        printf("Pemindahan gagal. Ruangan %c%d Sudah ditempati.\n", rowBaru+'A', columnBaru+1);
        return;
    }
    DataTypeRuangan temp=globalDenahRumahSakit.Ruangan[rowBaru][columnBaru];
    globalDenahRumahSakit.Ruangan[rowBaru][columnBaru]=globalDenahRumahSakit.Ruangan[rowLama][columnLama];
    globalDenahRumahSakit.Ruangan[rowLama][columnLama]=temp;
    printf("4\n");
    printf("Dr. %s berhasil dipindahkan dari ruangan %c%d ke ruangan %c%d.\n", getAccountName(globalDenahRumahSakit.Ruangan[rowBaru][columnBaru].idDokter, DATA_TYPE_DOCTOR), rowLama+'A', columnLama+1, rowBaru+'A', columnBaru+1);
}