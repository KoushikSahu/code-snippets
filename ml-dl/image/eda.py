import matplotlib.pyplot as plt
from PIL import Image
import numpy as np


def showImageGrid(df:"pd.DataFrame", 
                img_dir:"pathlib.Path", 
                image_path_col:"str", 
                image_label_col:"str", 
                num:"int"=9, 
                figsize"tuple(1,2)"=(3, 3)) -> "void":

    '''Image grid for single label image classification'''

    fig = plt.figure(figsize=figsize)

    for i in range(num):
        ax = fig.add_subplot(figsize[0], figsize[1], i+1)
        ax.set_title(df.loc[i, image_label_col])
        img = Image.open(img_dir/df.loc[i, image_path_col])
        plt.imshow(np.asarray(img))
    
    fig.tight_layout(pad=3.0)
