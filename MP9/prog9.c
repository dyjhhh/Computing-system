#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include "prog9.h"
 
//This program uses 4 functions to add a sound bite to a WAV file. little_endian_2 and 4
//change 2 or 4 bits respectively from big to little endian notation.
//read_file prints out the header of a wav file to the terminal based on a given input wav file/
//sound_bite reverses any little endians and reprints the first file to another file. When it gets to
//the data section, it adds a second sound bite to the original wav file, and stores the combination
//in the output as well.The results is an additional sound at a given input time.
 
//Switches a big endian form number of 2 bits to a little_endian form number
int little_endian_2(FILE *fptr){
 
    unsigned char num1,num2;
    int val = 0;
    fscanf(fptr,"%c%c",&num1,&num2);
   
    val += num2;
    val = val << 8;
    val += num1;
 
    return val;
}
//Switches a big endian form number of 4 bits to a little_endian form number
int little_endian_4(FILE *fptr){
 
    unsigned char num1,num2,num3,num4;
    int val = 0;
    fscanf(fptr,"%c%c%c%c",&num1,&num2,&num3,&num4);
   
    val += num4;
    val = val << 8;
    val += num3;
    val = val << 8;
    val += num2;
    val = val << 8;
    val += num1;
 
    return val;
 
}
 
//Prints the header of the Wav file based on a given input file
WAV *read_file(char *wavfile){
 
    FILE* wav_file = fopen(wavfile,"r");
    WAV* wav_ptr = (WAV *)malloc(sizeof(WAV));
    int i;
    char temp;
    //print ChunkID
    for(i=0;i<4;i++)
    {
        fscanf(wav_file,"%c",&temp);
        wav_ptr -> RIFF[i] = temp;
    }
    printf("RIFF: %c%c%c%c\n",wav_ptr ->RIFF[0],wav_ptr ->RIFF[1],wav_ptr ->RIFF[2],wav_ptr ->RIFF[3]);
 
    //print Chunksize
    wav_ptr -> ChunkSize = little_endian_4(wav_file);
    printf("Chunksize: %d\n",wav_ptr -> ChunkSize);
 
    //print Format
    for(i=0;i<4;i++)
    {
        fscanf(wav_file,"%c",&temp);
        wav_ptr -> WAVE[i] = temp;
    }    
    printf("WAVE: %c%c%c%c\n",wav_ptr ->WAVE[0],wav_ptr ->WAVE[1],wav_ptr ->WAVE[2],wav_ptr ->WAVE[3]);
 
    //print Subchunk1ID
    for(i=0;i<4;i++)
    {
        fscanf(wav_file,"%c",&temp);
        wav_ptr -> fmt[i] = temp;
    }
    printf("fmt: %c%c%c%c\n",wav_ptr ->fmt[0],wav_ptr ->fmt[1],wav_ptr ->fmt[2],wav_ptr ->fmt[3]);
 
    //print Subchunk1Size
    wav_ptr -> Subchunk1Size = little_endian_4(wav_file);
    printf("Subchunk1Size: %d\n",wav_ptr -> Subchunk1Size);
 
    //print Audioformat
    wav_ptr -> AudioFormat = little_endian_2(wav_file);
    printf("Audioformat: %d\n",wav_ptr -> AudioFormat);
   
    //print Numchannels
    wav_ptr -> NumChan = little_endian_2(wav_file);
    printf("Numchannels: %d\n",wav_ptr -> NumChan);
 
    //print SampleRate
    wav_ptr -> SamplesPerSec = little_endian_4(wav_file);
    printf("SampleRate: %d\n",wav_ptr -> SamplesPerSec);
 
    //print ByteRate
    wav_ptr -> bytesPerSec = little_endian_4(wav_file);
    printf("ByteRate: %d\n",wav_ptr -> bytesPerSec);
 
    //print BlockAlign
    wav_ptr -> blockAlign = little_endian_2(wav_file);
    printf("BlockAlign: %d\n",wav_ptr -> blockAlign);
         
    //print BitsPerSample
    wav_ptr -> bitsPerSample = little_endian_2(wav_file);
    printf("BitsPerSample: %d\n",wav_ptr -> bitsPerSample);
 
    //extra
    wav_ptr->extra = (char*) malloc( (wav_ptr -> Subchunk1Size - 16) * sizeof(char));
 
    for(i=0;i<wav_ptr -> Subchunk1Size - 16;i++)
    {
        fscanf(wav_file,"%c",&temp);
        wav_ptr -> extra[i] = temp;
    }
 
    //print Subchunk2ID
    for(i=0;i<4;i++)
    {
        fscanf(wav_file,"%c",&temp);
        wav_ptr -> Subchunk2ID[i] = temp;
    }
    printf("Subchunk2ID: %c%c%c%c\n",wav_ptr ->Subchunk2ID[0],wav_ptr ->Subchunk2ID[1],wav_ptr ->Subchunk2ID[2],wav_ptr ->Subchunk2ID[3]);
 
    //print Subchunk2Size
    wav_ptr -> Subchunk2Size = little_endian_4(wav_file);
    printf("Subchunk2Size: %d\n",wav_ptr -> Subchunk2Size);
 
    //data
    wav_ptr->data= (short int*)malloc( ((wav_ptr->Subchunk2Size*8)/wav_ptr->bitsPerSample) * sizeof(short int));
 
    for(i=0;i<(wav_ptr->Subchunk2Size*8)/wav_ptr->bitsPerSample;i++)
    {
        wav_ptr->data[i] = little_endian_2(wav_file);
    }
 
    fclose(wav_file);
    return wav_ptr;
 
}
 
 
//Takes a wav file and adds a soundbite to it at a given time; new wav file stored in outfile
void sound_bite(WAV *inwav, WAV *bitewav, char *outfile, double time){
 
    FILE* out = fopen(outfile,"w");
    char c0,c1,c2,c3;
    int i;
   
    //Reprints RIFF
    for(i=0;i<4;i++)
        fprintf(out,"%c",inwav -> RIFF[i]);
   
    //Reverse endian chunksize
    c0 = (inwav->ChunkSize);
    c1 = (inwav->ChunkSize>>8);
    c2 = (inwav->ChunkSize>>16);
    c3 = (inwav->ChunkSize>>24);
    fprintf(out,"%c%c%c%c",c0,c1,c2,c3);
   
    //Reprints WAVE
    for(i=0;i<4;i++)
        fprintf(out,"%c",inwav -> WAVE[i]);
 
    //Reprints fmt
    for(i=0;i<4;i++)
        fprintf(out,"%c",inwav -> fmt[i]);
 
    //Reverse endian subchunk1size
    c0 = (inwav->Subchunk1Size);
    c1 = (inwav->Subchunk1Size>>8);
    c2 = (inwav->Subchunk1Size>>16);
    c3 = (inwav->Subchunk1Size>>24);
    fprintf(out,"%c%c%c%c",c0,c1,c2,c3);
 
    //Reverse endian audioformat
    c0 = (inwav->AudioFormat);
    c1 = (inwav->AudioFormat>>8);
    fprintf(out,"%c%c",c0,c1);
 
    //Reverse endian numberofchannels
    c0 = (inwav->NumChan);
    c1 = (inwav->NumChan>>8);
    fprintf(out,"%c%c",c0,c1);
 
    //Reverse endian samplespersec
    c0 = (inwav->SamplesPerSec);
    c1 = (inwav->SamplesPerSec>>8);
    c2 = (inwav->SamplesPerSec>>16);
    c3 = (inwav->SamplesPerSec>>24);
    fprintf(out,"%c%c%c%c",c0,c1,c2,c3);
 
    //Reverse endian bytespersec
    c0 = (inwav->bytesPerSec);
    c1 = (inwav->bytesPerSec>>8);
    c2 = (inwav->bytesPerSec>>16);
    c3 = (inwav->bytesPerSec>>24);
    fprintf(out,"%c%c%c%c",c0,c1,c2,c3);
 
    //Reverse endian blockalign
    c0 = (inwav->blockAlign);
    c1 = (inwav->blockAlign>>8);
    fprintf(out,"%c%c",c0,c1);
 
    //Reverse endian bitspersample
    c0 = (inwav->bitsPerSample);
    c1 = (inwav->bitsPerSample>>8);
    fprintf(out,"%c%c",c0,c1);
 
    //Reprints extra
    for(i=0;i<inwav ->Subchunk1Size - 16;i++)
        fprintf(out,"%c",inwav -> extra[i]);
 
    //Reprints Subchunck2ID
    for(i=0;i<4;i++)
        fprintf(out,"%c",inwav -> Subchunk2ID[i]);    
 
    //Reverse endian subchunk2size
    c0 = (inwav->Subchunk2Size);
    c1 = (inwav->Subchunk2Size>>8);
    c2 = (inwav->Subchunk2Size>>16);
    c3 = (inwav->Subchunk2Size>>24);
    fprintf(out,"%c%c%c%c",c0,c1,c2,c3);    
 
    double start_time= inwav->SamplesPerSec*2*time;
    double end_time = bitewav->Subchunk2Size*8/bitewav->bitsPerSample;
    double stop = inwav->Subchunk2Size*8/inwav->bitsPerSample;
   
    //time before sound bite
    for(i=0; i<start_time;i++)
    {  
        c0=inwav->data[i];
        c1=inwav->data[i]>>8;
 
        fprintf(out,"%c%c",c0,c1);
    }
   
    //time with sound bite
    int j =0;
    for(i=start_time;i<end_time+start_time;i++)
    {
        char a= inwav->data[i];
        char b= inwav->data[i]>>8;
        char c= bitewav->data[j];
        char d= bitewav->data[j]>>8;
        c0 = a+c;
        c1= b+d;
        fprintf(out,"%c%c",c0,c1);
        j++;
    }
   
    //time after soundbite
    for(i=end_time+start_time; i<stop;i++)
    {  
        c0=inwav->data[i];
        c1=inwav->data[i]>>8;
 
        fprintf(out,"%c%c",c0,c1);
    }
    fclose(out);
   
}
 
 
//Extra credit
void lo_pass(WAV *inwav, char *outfile, int freq){
 
}