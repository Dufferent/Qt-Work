source /opt/fsl-imx-x11/4.1.15-2.1.0/environment-setup-cortexa7hf-neon-poky-linux-gnueabi
#! /bin/bash
read -p "请输入工程名:<eg::><xny.pro>" pro_name
printf "\n"
qmake $pro_name
make

