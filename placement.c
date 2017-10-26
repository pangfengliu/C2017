void place(int bucket[1024], int N, int ball[16384],int M,
	   int method,int result[16384])
{
  switch (method) {
  case 0:
    for (int b = 0; b < M; b++) {
      int found = 0;
      for (int k = 0; k < N && found == 0; k++)
	if (ball[b] <= bucket[k]) {
	  result[b] = k;
	  bucket[k] -= ball[b];
	  found = 1;
	}
      if (found == 0)
	result[b] = -1;
    }
    break;

  case 1:
    for (int b = 0; b < M; b++) {
      int min = 1000000000, minBid;
      int found = 0;
      for (int k = 0; k < N; k++)
	if (ball[b] <= bucket[k] && bucket[k] < min) {
	  min = bucket[k];
	  minBid = k;
	  found = 1;
	}
      if (found == 0)
	result[b] = -1;
      else {
	result[b] = minBid;
	bucket[minBid] -= ball[b];
      }
    }
    break;

  case 2:
    for (int b = 0; b < M; b++) {
      int max = -1, maxBid;
      int found = 0;
      for (int k = 0; k < N; k++)
	if (ball[b] <= bucket[k] && bucket[k] >= max) {
	  max = bucket[k];
	  maxBid = k;
	  found = 1;
	}
      if (found == 0)
	result[b] = -1;
      else {
	result[b] = maxBid;
	bucket[maxBid] -= ball[b];
      }
    }
    break;

  }
}
