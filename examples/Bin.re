open Revery;

let init = (app) => {
    let _ = app#createWindow("test");

    let%lwt b = File.openAsync("binary.dat");
    let length = Bigarray.Array1.dim(b);

    for(i in 0 to length - 1) {
       print_endline (string_of_int(Bigarray.Array1.get(b, i))); 
    }

    Lwt.return ();
};

/* Js.Unsafe.fun_call(Js.Unsafe.js_expr("console.log"), [||]); */

App.start(init);
