package VISAO;

import DAO.CandidatoDAO;
import DAO.VotoDAO;
import MODELO.Candidato;
import MODELO.Eleitor;
import URNA.Urna;
import javax.swing.JOptionPane;

/**
 *
 * @author cambraia
 */
public class ConsoleUrna extends javax.swing.JFrame {
	private int nUrna = 0;
	private Urna instancia = null;
        private Eleitor User = null;

	public ConsoleUrna() {
		initComponents();
	}

	public ConsoleUrna(Urna instancia,Eleitor User, int nUrna) {
                //Argumentos
		this.instancia=instancia;
                this.nUrna = nUrna;//Qual o numero da Urna Criada
		this.User = User;//Quem esta votando	
		//Iniciando Tela
		initComponents();
                this.setTitle("Urna");
		Confirma.setEnabled(false);
                this.setVisible(true);

	}

	@SuppressWarnings("unchecked")
	// <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jButton6 = new javax.swing.JButton();
        jButton7 = new javax.swing.JButton();
        jButton8 = new javax.swing.JButton();
        jButton9 = new javax.swing.JButton();
        jButton0 = new javax.swing.JButton();
        Limpar = new javax.swing.JButton();
        CampoCandidato = new javax.swing.JTextField();
        Confirma = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        ApagarNumero = new javax.swing.JButton();
        BotaoBranco = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        jButton1.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton1.setText("1");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton2.setText("2");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton3.setText("3");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton4.setText("4");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jButton5.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton5.setText("5");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jButton6.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton6.setText("6");
        jButton6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton6ActionPerformed(evt);
            }
        });

        jButton7.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton7.setText("7");
        jButton7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton7ActionPerformed(evt);
            }
        });

        jButton8.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton8.setText("8");
        jButton8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton8ActionPerformed(evt);
            }
        });

        jButton9.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton9.setText("9");
        jButton9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton9ActionPerformed(evt);
            }
        });

        jButton0.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        jButton0.setText("0");
        jButton0.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton0ActionPerformed(evt);
            }
        });

        Limpar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ICONES/apagar.png"))); // NOI18N
        Limpar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LimparActionPerformed(evt);
            }
        });

        CampoCandidato.setEditable(false);
        CampoCandidato.setFont(new java.awt.Font("Ubuntu", 0, 36)); // NOI18N
        CampoCandidato.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                CampoCandidatoMouseClicked(evt);
            }
        });
        CampoCandidato.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CampoCandidatoActionPerformed(evt);
            }
        });

        Confirma.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ICONES/confirmar.png"))); // NOI18N
        Confirma.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ConfirmaActionPerformed(evt);
            }
        });

        jLabel1.setText("Nome Partido");

        jLabel2.setText("Numero Partido");

        jLabel3.setText("Nome Candidato");

        ApagarNumero.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ICONES/cancelar.png"))); // NOI18N
        ApagarNumero.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ApagarNumeroActionPerformed(evt);
            }
        });

        BotaoBranco.setFont(new java.awt.Font("Ubuntu", 0, 24)); // NOI18N
        BotaoBranco.setText("Branco");
        BotaoBranco.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BotaoBrancoActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(Limpar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(ApagarNumero)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(Confirma)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jButton0, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(BotaoBranco, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jButton7, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jButton8, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jButton9, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jButton4, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jButton5, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jButton6, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addComponent(CampoCandidato))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 80, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 129, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 129, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 129, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(54, 54, 54))))
        );

        layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {ApagarNumero, Confirma, Limpar, jButton0, jButton1, jButton2, jButton3, jButton4, jButton5, jButton6, jButton7, jButton8, jButton9});

        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(52, 52, 52)
                .addComponent(CampoCandidato, javax.swing.GroupLayout.PREFERRED_SIZE, 70, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton3)
                    .addComponent(jButton2)
                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 70, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton4, javax.swing.GroupLayout.PREFERRED_SIZE, 54, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton5)
                    .addComponent(jButton6)
                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 70, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton7)
                    .addComponent(jButton8)
                    .addComponent(jButton9)
                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 70, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton0, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(BotaoBranco, javax.swing.GroupLayout.PREFERRED_SIZE, 58, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Limpar)
                    .addComponent(ApagarNumero)
                    .addComponent(Confirma))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        layout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {ApagarNumero, Confirma, Limpar, jButton0, jButton1, jButton2, jButton3, jButton4, jButton5, jButton6, jButton7, jButton8, jButton9});

        pack();
    }// </editor-fold>//GEN-END:initComponents

	private Candidato MostraCandidato() {
		if (CampoCandidato.getText().length() == 5) {
			// Pega Numero do terminal e pesquisa se há algum candidato com esse numero
                        
			Candidato cand = instancia.ProcuraCandidato(CampoCandidato.getText());
			if (cand == null) {// Nao há nimguem com esse numero
				jLabel3.setText("Nome Candidato");
				jLabel2.setText("Numero Partido");
				jLabel1.setText("Nome Partido");
				cand = null;
				return null;
			} else {
				jLabel3.setText(cand.getNome());
				jLabel2.setText("" + cand.getPartido().getNumero());
				jLabel1.setText(cand.getPartido().getNOME());
				return cand;
			}
		} else {
			jLabel3.setText("Nome Candidato");
			jLabel2.setText("Numero Partido");
			jLabel1.setText("Nome Partido");

			return null;
		}
	}

	private void setOk() {
		Confirma.setEnabled(true);
	}

	private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton1ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "1");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton1ActionPerformed

	private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton2ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "2");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton2ActionPerformed

	private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton3ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "3");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton3ActionPerformed

	private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton4ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "4");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
	}// GEN-LAST:event_jButton4ActionPerformed

	private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton5ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "5");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton5ActionPerformed

	private void jButton6ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton6ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "6");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton6ActionPerformed

	private void jButton7ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton7ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "7");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton7ActionPerformed

	private void jButton8ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton8ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "8");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton8ActionPerformed

	private void jButton9ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton9ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "9");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton9ActionPerformed

	private void jButton0ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton0ActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() < 5) {
			CampoCandidato.setText(CampoCandidato.getText() + "0");
			if (CampoCandidato.getText().length() == 5) {
				setOk();
			}
		}
		MostraCandidato();
	}// GEN-LAST:event_jButton0ActionPerformed

	private void LimparActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_LimparActionPerformed
		// TODO add your handling code here:
		CampoCandidato.setText("");
		Confirma.setEnabled(false);
		MostraCandidato();
	}// GEN-LAST:event_LimparActionPerformed

	private void CampoCandidatoActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_CampoCandidatoActionPerformed
		// TODO add your handling code here:
		CampoCandidato.setEditable(false);

	}// GEN-LAST:event_CampoCandidatoActionPerformed

	private void ApagarNumeroActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_ApagarNumeroActionPerformed
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() != 0) {
			String str = CampoCandidato.getText();
			StringBuilder w = new StringBuilder(str);
			str = String.valueOf(w.deleteCharAt(str.length() - 1));
			CampoCandidato.setText(str);
			Confirma.setEnabled(false);

		}
		MostraCandidato();
	}// GEN-LAST:event_ApagarNumeroActionPerformed

	private void ConfirmaActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_ConfirmaActionPerformed
		// TODO add your handling code here:
		String texto = CampoCandidato.getText();
		Confirma.setEnabled(true);
		Candidato cand = MostraCandidato();
		if(cand != null) {
			System.out.println("Voto Valido");
			instancia.Votar(User, cand, nUrna);
                        instancia.Send();
		}else {//Voto Nulo
			System.out.println("Voto Invalido");
                        JOptionPane.showMessageDialog(null, "Voto invalido logo não sera contabilizado");
                        
		}
                instancia.Deslogar();
                new TelaLogin(instancia).setVisible(true);
		this.dispose();
	}// GEN-LAST:event_ConfirmaActionPerformed

	private void CampoCandidatoMouseClicked(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_CampoCandidatoMouseClicked
		// TODO add your handling code here:
		if (CampoCandidato.getText().length() != 5) {
			Confirma.setEnabled(false);
		} else {
			Confirma.setEnabled(true);
		}
	}// GEN-LAST:event_CampoCandidatoMouseClicked

	private void BotaoBrancoActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_BotaoBrancoActionPerformed
		// TODO add your handling code here:
		// Voto em branco não é contabilizado nem armazenado
                System.out.println("Voto não contabilizado");
                instancia.Deslogar();
                new TelaLogin(instancia).setVisible(true);
		this.dispose();
	}// GEN-LAST:event_BotaoBrancoActionPerformed
	/**/

	/**
	 * @param args the command line arguments
	 */
	public static void main(String args[]) {
		/* Set the Nimbus look and feel */
		// <editor-fold defaultstate="collapsed" desc=" Look and feel setting code
		// (optional) ">
		/*
		 * If Nimbus (introduced in Java SE 6) is not available, stay with the default
		 * look and feel. For details see
		 * http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html
		 */
		try {
			for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
				if ("Nimbus".equals(info.getName())) {
					javax.swing.UIManager.setLookAndFeel(info.getClassName());
					break;
				}
			}
		} catch (ClassNotFoundException ex) {
			java.util.logging.Logger.getLogger(ConsoleUrna.class.getName()).log(java.util.logging.Level.SEVERE, null,
					ex);
		} catch (InstantiationException ex) {
			java.util.logging.Logger.getLogger(ConsoleUrna.class.getName()).log(java.util.logging.Level.SEVERE, null,
					ex);
		} catch (IllegalAccessException ex) {
			java.util.logging.Logger.getLogger(ConsoleUrna.class.getName()).log(java.util.logging.Level.SEVERE, null,
					ex);
		} catch (javax.swing.UnsupportedLookAndFeelException ex) {
			java.util.logging.Logger.getLogger(ConsoleUrna.class.getName()).log(java.util.logging.Level.SEVERE, null,
					ex);
		}
		// </editor-fold>
		// </editor-fold>

		/* Create and display the form */
		java.awt.EventQueue.invokeLater(new Runnable() {
			public void run() {
				new ConsoleUrna().setVisible(true);
			}
		});
	}

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton ApagarNumero;
    private javax.swing.JButton BotaoBranco;
    private javax.swing.JTextField CampoCandidato;
    private javax.swing.JButton Confirma;
    private javax.swing.JButton Limpar;
    private javax.swing.JButton jButton0;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JButton jButton6;
    private javax.swing.JButton jButton7;
    private javax.swing.JButton jButton8;
    private javax.swing.JButton jButton9;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    // End of variables declaration//GEN-END:variables
}
