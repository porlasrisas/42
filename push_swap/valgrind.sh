#!/bin/bash
# valgrind_tester.sh – Script para comprobar fugas de memoria en push_swap

# Lista de casos de prueba (puedes agregar o modificar según tus necesidades)
TESTS=(
    "4 67 3 87 23"
    "-34 12 9"
    "1 2 3 4 5"
    "5 4 3 2 1"
    "42 -42 2147483647 -2147483648"
    "-228 -761 -456 -293 688 861 58 198 653 -530 795 978 -336 733 36 687 325 -634 998 -537 -964 -149 -932 737 -209 -415 -205 68 -551 -687 -88 -951 356 -245 153 580 -685 934 -542 -808 980 352 202 256 -611 -335 49 147 -846 -345 -445 47 459 440 -383 -280 -739 773 718 -823 -7 -435 -244 -65 926 -68 -403 40 299 -288 -767 -911 424 868 -337 -242 237 208 720 -819 901 479 -219 187 364 -787 -84 875 -178 101 894 -607 641 -913 -214 -9 326 257 -826 -54 474 -327 -198 840 416 272 849 -802 -34 -930 -837 910 682 -411 -363 139 638 346 833 576 373 -731 338 35 -19 430 -595 220 -792 889 -224 -907 -426 449 -505 -574 266 376 161 127 -1 226 -450 862 301 129 648 184 -981 138 -658 866 377 349 863 -220 809 408 -70 -517 945 378 991 -804 -931 515 -236 -326 -428 282 501 -339 -776 -10 -354 606 -915 -237 -181 452 -91 -492 -667 -691 -63 -840 -407 -231 713 797 128 -506 821 374 -963 -851 53 722 274 343 84 636 298 259 -532 11 -227 522 484 -631 783 -148 -710 -642 917 -3 205 986 -173 -566 -390 -970 89 -298 271 963 842 -648 839 -108 -984 -264 -482 0 -22 843 -822 617 563 -94 996 92 207 -6 859 -230 -421 691 799 712 -425 -901 -436 -190 275 46 -121 27 552 -303 -387 414 -25 -104 388 603 892 -50 72 568 589 -275 678 -707 -751 493 -839 962 -879 -722 -249 724 -430 438 18 971 -488 368 197 317 714 33 -854 914 -780 485 846 692 997 -666 -957 341 666 -579 -334 -285 922 -875 -511 96 -961 9 950 157 154 31 -769 -501 80 693 -679 -144 -312 542 29 -481 -115 -101 -580 -255 427 387 -478 -183 -477 -378 965 -87 961 212 913 -998 242 448 360 -377 881 233 270 -927 -414 433 -781 -571 361 428 -643 -603 -74 880 -616 -431 -771 690 -677 695 -429 505 -762 887 -493 315 817 -758 -292 -57 -331 905 -752 -949 -703 146 -433 976 937 -919 -417 -884 -158 -319 848 -763 -479 1 365 122 -903 939 -322 436 143 221 213 -32 83 -833 150 432 583 -947 938 632 81 -111 876 -593 171 564 -281 -346 696 -554 -497 111 579 267 -323 652 323 -28 -817 -47 -226 231 717 769 805 -926 -678 -904 921 -663 684 -671 -258 188 -29 492 322 -369 -240 -755 709 -730 -256 673 -888 457 -438 394 -585 74 -199 73 -461 -38 -89 -626 650 -159 -994 -796 173 -265 729 -434 -491 -276 -916 26 585 166 4 -653 241 20 -870 633 -965 -538 -162 551 466 403 -844 421 -355 820 -76 -512"
)

# Recorre cada test y ejecuta push_swap con Valgrind.
for test in "${TESTS[@]}"
do
    echo "Ejecutando test: $test"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
      ./push_swap $test > /dev/null 2>&1
    echo "------------------------------------"
done

echo "Pruebas de Valgrind completadas."
