for(i=n-1;i>=1;-i)
    for(j=1j<=i;+j)
        if(A[j]Ð¡>A[j+1])
        A[j]=A[j+1]¶Ô»»£»

p->prior=q->next;p->prior=q;q->next=p;p->prior->next=q;q->prior=p->prior;

p->prior->next=q;q->prior=p;q->prior=p->prior;p->prior=q;