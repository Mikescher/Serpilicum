template <typename T> T **allocateDynamicArray( int nRows, int nCols) {
      T **dynamicArray;

      dynamicArray = new T*[nRows];
      for( int i = 0 ; i < nRows ; i++ )
      dynamicArray[i] = new T [nCols];

      return dynamicArray;
}

template <typename T> void freeDynamicArray(T** dArray) {
      delete [] *dArray;
      delete [] dArray;
}