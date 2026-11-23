// EcoCompacta: pinon y cremallera parametricos, unidades mm
// Anteproyecto basado en cotas compartidas; no fabricar sin revisar cotas marcadas TBD.
$fn=96;
vista="conjunto"; // pinon, cremallera, conjunto
modulo=1.5; angulo=20; dientes_pinon=18;
espesor_pinon=10; d_ext=30; d_primitivo=27;
diam_eje=5.25; entre_caras=3.25;
paso=4.71; n_dientes=64; largo=310;
ancho_cremallera=10.6; profundidad_diente=3.375;
ancho_cara=10.6; espesor_pestana=4; diam_hoyo=3.5;
margen_hoyos=15; // provisional: posicion no acotada en croquis
extension_pestana=14; // provisional: ancho no acotado
rp=d_primitivo/2; rb=rp*cos(angulo); rr=rp-1.25*modulo; ro=d_ext/2;
ded=1.25*modulo; add=profundidad_diente-ded;
wr=paso/2+2*ded*tan(angulo);
wt=paso/2-2*add*tan(angulo);
primer_centro=(largo-(n_dientes-1)*paso)/2;
function inv(r,b)=sqrt(max(0,(r/b)*(r/b)-1))*180/PI-acos(min(1,b/r));
function half(r)=90/dientes_pinon+inv(rp,rb)-inv(max(r,rb),rb);
module tooth2d(){
 n=12; ar=half(rr); at=half(ro);
 fl=[for(i=[0:n]) let(r=rb+(ro-rb)*i/n,a=half(r)) [r*cos(-a),r*sin(-a)]];
 cap=[for(j=[0:4]) let(a=-at+2*at*j/4) [ro*cos(a),ro*sin(a)]];
 fl2=[for(i=[n:-1:0]) let(r=rb+(ro-rb)*i/n,a=half(r)) [r*cos(a),r*sin(a)]];
 polygon(concat([[rr*cos(-ar),rr*sin(-ar)]],fl,cap,fl2,[[rr*cos(ar),rr*sin(ar)]]));
}
module gear2d(){
 union(){circle(r=rr); for(i=[0:dientes_pinon-1]) rotate(i*360/dientes_pinon) tooth2d();}
}
module doubleD(){
 intersection(){circle(d=diam_eje); square([diam_eje+1,entre_caras],center=true);}
}
module pinon(){
 difference(){
  linear_extrude(height=espesor_pinon) gear2d();
  translate([0,0,-0.5]) linear_extrude(height=espesor_pinon+1) doubleD();
 }
}
module toothRack(cx){
 polygon([[cx-wr/2,0],[cx-wt/2,profundidad_diente],[cx+wt/2,profundidad_diente],[cx+wr/2,0]]);
}
module rack2d(){
 union(){
  translate([0,-ancho_cremallera]) square([largo,ancho_cremallera]);
  for(i=[0:n_dientes-1]) toothRack(primer_centro+i*paso);
 }
}
module rack(){
 difference(){
  union(){
   linear_extrude(height=ancho_cara) rack2d();
   // pestaña referencial: ancho/posicion no definidos en croquis
   translate([0,-ancho_cremallera-extension_pestana,0])
    cube([largo,extension_pestana,espesor_pestana]);
  }
  for(x=[margen_hoyos,largo-margen_hoyos])
   translate([x,-ancho_cremallera-extension_pestana/2,-0.5])
    cylinder(d=diam_hoyo,h=ancho_cara+1);
 }
}
module conjunto(){
 rack();
 translate([primer_centro+14,profundidad_diente+rp,0]) pinon();
}
if(vista=="pinon") pinon();
else if(vista=="cremallera") rack();
else conjunto();
// Supuestos: perfil involuta, modulo 1.5, presion 20 grados, dedendo 1.25*m.
// Verificar 10.6 y 3.375, convención 64 dientes/pasos, holgura, soportes y agujeros.
// El largo 310 se toma como longitud total; 64 centros espaciados 4.71 mm se centran.
// No representa carcasa completa ni demuestra integración con Fusion.
