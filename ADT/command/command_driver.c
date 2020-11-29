#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../point/point.h"
#include "command.h"

int main()
{
    COMMAND C;
    //make empty command
    MakeEmptyCOMMAND(&C); // diinisialisasi -1
    printf("Isi command dengan fungsi makeEMptycommand:\n");
    TulisCOMMAND(C);
    printf("\nmembuat command dengan fungsi MakeCommand lalu menampilkan hasilnya: \n");
    COMMAND D = MakeCOMMAND(1, 1, 1, 1, 1, MakePOINT(2, 3), 1);
    TulisCOMMAND(D);
    return 0;
}