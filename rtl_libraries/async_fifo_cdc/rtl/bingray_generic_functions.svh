function int bin2gray_fun (int in_bin);
    return in_bin ^ (in_bin >> 1);
endfunction : bin2gray_fun

function int gray2bin_fun (int in_gray);
    // Taking xor until n becomes zero
    int out_bin;
    for (; in_gray; in_gray = in_gray >> 1)
        out_bin ^= in_gray;
    return out_bin;
endfunction : gray2bin_fun